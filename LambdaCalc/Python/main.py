#!/usr/bin/env python3

from lark import Lark, Transformer
from enum import Enum
from copy import deepcopy

class NodeType(Enum):
	Ident = 0
	Lambda = 1
	Application = 2
	Assignment = 3
	Undef = 4

grammar = '''
	start		: expr -> only_arg
				| assignment -> only_arg
				| undef -> only_arg
	assignment	: ident "=" expr -> assignment_expr
	undef		: "undef" ident -> undef_expr
	expr		: lambda -> only_arg
				| application -> only_arg
				| ident -> only_arg
	lambda		: "lambda" ident "." expr -> lambda_expr
	application	: "(" expr expr ")" -> application_expr
	ident		: /[a-z_A-Z][a-z_A-Z0-9]*/ -> ident_expr

	%ignore " "
'''

class LambdaTransformer(Transformer):
	lambda_expr = lambda args: [NodeType.Lambda, args[0], args[1]]
	application_expr = lambda args: [NodeType.Application, args[0], args[1]]
	ident_expr = lambda args: [NodeType.Ident, str(args[0])]
	assignment_expr = lambda args: [NodeType.Assignment, args[0], args[1]]
	undef_expr = lambda args: [NodeType.Undef, args[0]]
	only_arg = lambda args: args[0]

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
			reduce(expr)
	elif expr[0] == NodeType.Assignment:
		reduce(expr[2])
		variables[expr[1][1]] = deepcopy(expr[2])
		expr[:] = expr[2]
	elif expr[0] == NodeType.Ident:
		if expr[1] in variables:
			expr[:] = deepcopy(variables[expr[1]])

variables = {}

parser = Lark(grammar, parser='lalr', transformer=LambdaTransformer)

tests = [
	('x', 'x'),
	('(x y)', '(x y)'),
	('lambda x.y', 'λx.y'),
	('lambda x.lambda y.(x y)', 'λx.λy.(x y)'),
	('(lambda x.(y x) z)', '(y z)'),
	('(lambda x.(x x) lambda y.y)', 'λy.y')]
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
		try:
			result = parser.parse(inExpr)
			if result[0] == NodeType.Undef:
				del variables[result[1][1]]
			else:
				reduce(result)
				result = expr_to_str(result)
				print(result)
				if isTest:
					if result == expected:
						print('\033[32mPassed ✓\033[37m')
					else:
						print('\033[31mFailed X\033[37m')
						print('Expected: %s' % expected)
		except RecursionError:
			print('\033[31mError: infinite loop\033[37m')
		except:
			print('\033[31mError: invalid syntax\033[37m')
	print()
