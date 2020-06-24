#!/usr/bin/env python3


def calc(expr):
    try:
        return float(expr)
    except ValueError:
        if expr in variables.keys():
            return variables[expr]

        i = expr.find('(')
        if ('(' in expr) ^ (')' in expr):
            raise Exception
        if i != -1:
            j = i
            brackets = 1
            while brackets:
                j += 1
                if expr[j] == '(':
                    brackets += 1
                elif expr[j] == ')':
                    brackets -= 1
            return calc(expr[:i] + str(calc(expr[i + 1:j])) + expr[j + 1:])

        i = expr.rfind('+')
        j = expr.rfind('-')
        if i != -1 and (j == -1 or j < i):
            return calc(expr[:i]) + calc(expr[i + 1:])
        if j != -1 and (i == -1 or i < j):
            return calc(expr[:j]) - calc(expr[j + 1:])

        i = expr.rfind('*')
        j = expr.rfind('/')
        if i != -1 and (j == -1 or j < i):
            return calc(expr[:i]) * calc(expr[i + 1:])
        if j != -1 and (i == -1 or i < j):
            try:
                return calc(expr[:j]) / calc(expr[j + 1:])
            except ZeroDivisionError as err:
                raise err


variables = {}


def main():
    while True:
        in_expr = input('> ')

        if in_expr.lower() in ['quit', 'q', 'exit']:
            break

        in_expr = in_expr.replace(' ', '')

        try:
            i = in_expr.find('=')
            if i != -1:
                start = i + 1
                var = in_expr[:i]
            else:
                start = 0
                var = None

            result = calc(in_expr[start:])
            if result == int(result):
                result = int(result)

            if var is not None:
                variables[var] = result

            print(result)
        except ZeroDivisionError:
            print('Tried to divide by zero!')
        except:
            print('Syntax error!')


if __name__ == "__main__":
    main()
