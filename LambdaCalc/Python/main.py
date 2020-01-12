#!/usr/bin/env python3

from lark import Lark, Transformer
from enum import Enum
from copy import deepcopy

class NodeType(Enum):
	Ident = 0
	Lambda = 1
	Application = 2

grammar = '''
	start		: expr -> only_arg
	expr		: lambda -> only_arg
				| application -> only_arg
				| ident -> only_arg
	lambda		: "lambda" ident "." expr -> lambda_expr
	application	: "(" expr expr ")" -> application_expr
	ident		: /[a-z_A-Z][a-z_A-Z0-9]*/ -> ident_expr

	%ignore " "
'''

class LambdaTransformer(Transformer):
	def lambda_expr(self, args):
		return [NodeType.Lambda, args[0], args[1]]
	def application_expr(self, args):
		return [NodeType.Application, args[0], args[1]]
	def ident_expr(self, args):
		return [NodeType.Ident, str(args[0])]
	def only_arg(self, args):
		return args[0]

def expr_to_str(expr):
	if expr[0] == NodeType.Lambda:
		return 'λ%s.%s' % (expr_to_str(expr[1]), expr_to_str(expr[2]))
	elif expr[0] == NodeType.Application:
		return '(%s %s)' % (expr_to_str(expr[1]), expr_to_str(expr[2]))
	elif expr[0] == NodeType.Ident:
		return expr[1]

def apply(expr, var, value):
	if expr[0] == NodeType.Application or expr[0] == NodeType.Lambda:
		apply(expr[1], var, value)
		apply(expr[2], var, value)
	elif expr[0] == NodeType.Ident and expr[1] == var[1]:
		expr[:] = deepcopy(value)

def reduce(expr):
	if expr[0] == NodeType.Lambda:
		reduce(expr[1])
		reduce(expr[2])
	elif expr[0] == NodeType.Application:
		reduce(expr[1])
		reduce(expr[2])
		if expr[1][0] == NodeType.Lambda:
			apply(expr[1][2], expr[1][1], expr[2])
			expr[:] = expr[1][2]

parser = Lark(grammar, parser='lalr', transformer=LambdaTransformer())

tests = [
	('x', 'x'),
	('(x y)', '(x y)'),
	('lambda x.y', 'λx.y'),
	('lambda x.lambda y.(x y)', 'λx.λy.(x y)'),
	('(lambda x.(y x) z)', '(y z)')]
testNumber = 0
runTests = True

while True:
		if runTests and tests:
			isTest = True
			inExpr, expected = tests.pop(0)
			print('Test %d> %s' % (testNumber, inExpr))
			testNumber += 1
		else:
			isTest = False
			inExpr = input('> ')
			if inExpr.lower() in ('q', 'quit', 'exit'):
				break
		if len(inExpr) > 0:
			result = parser.parse(inExpr)
			reduce(result)
			result = expr_to_str(result)
			print(result)
			if isTest:
				if result == expected:
					print('\033[1;32;40mPassed ✓\033[1;37;40m')
				else:
					print('\033[1;31;40mFailed X\033[1;37;40m')
					print('Expected: %s' % expected)
		print()
