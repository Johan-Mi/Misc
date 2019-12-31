#!/usr/bin/env python3

def calc(expr):
	try:
		return float(expr)
	except:
		if expr in variables.keys():
			return variables[expr]

		i = expr.find('(')
		j = expr.rfind(')')
		if (i == -1) ^ (j == -1):
			raise Exception
		if i != -1 and j != -1:
			return calc(expr[:i] + str(calc(expr[i + 1:j])) + expr[j + 1:])

		i = expr.find('+')
		j = expr.find('-')
		if i != -1 and (j == -1 or j > i):
			return calc(expr[:i]) + calc(expr[i + 1:])
		if j != -1 and (i == -1 or i > j):
			return calc(expr[:j]) - calc(expr[j + 1:])

		i = expr.find('*')
		j = expr.find('/')
		if i != -1 and (j == -1 or j > i):
			return calc(expr[:i]) * calc(expr[i + 1:])
		if j != -1 and (i == -1 or i > j):
			try:
				return calc(expr[:j]) / calc(expr[j + 1:])
			except ZeroDivisionError as e:
				raise e

variables = {}

while True:
	inExpr = input('> ')

	exprCopy = inExpr
	exprCopy.lower()
	if exprCopy in ['quit', 'q', 'exit']:
		break

	inExpr = inExpr.replace(' ', '')

	try:
		i = inExpr.find('=')
		if i != -1:
			start = i + 1
			var = inExpr[:i]
		else:
			start = 0
			var = None

		result = calc(inExpr[start:])
		if result == int(result):
			result = int(result)

		if var is not None:
			variables[var] = result

		print(result)
	except ZeroDivisionError:
		print('Tried to divide by zero!')
	except:
		print('Syntax error!')
