#!/usr/bin/env python3

from lark import Lark, Transformer

grammar = '''
		start		: expr -> get_num
		expr		: add -> get_num
					| sub -> get_num
					| mul -> get_num
					| div -> get_num
					| num -> num_literal
		num			: "(" expr ")" -> get_num
					| NUMBER -> num_literal
					| negate -> get_num
		add			: expr "+" expr -> add_expr
		sub			: expr "-" expr -> sub_expr
		mul			: num "*" num -> mul_expr
		div			: num "/" num -> div_expr
		negate		: "-" num -> negate_expr

		%import common.NUMBER
		%ignore " "
	'''

class CalcTransformer(Transformer):
	def get_num(self, args):
		return args[0]
	def num_literal(self, args):
		return float(args[0])
	def add_expr(self, args):
		return float(args[0]) + float(args[1])
	def sub_expr(self, args):
		return float(args[0]) - float(args[1])
	def mul_expr(self, args):
		return float(args[0]) * float(args[1])
	def div_expr(self, args):
		return float(args[0]) / float(args[1])
	def negate_expr(self, args):
		return -args[0]

parser = Lark(grammar, parser='lalr', transformer=CalcTransformer())

try:
	result = parser.parse(input('> '))
	if result == int(result):
		result = int(result)
	print(result)
except ZeroDivisionError:
	print('Tried to divide by zero!')
except:
	print('Syntax error!')
