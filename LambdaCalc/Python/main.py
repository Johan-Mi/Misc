#!/usr/bin/env python3

from enum import Enum
from copy import deepcopy
from lark import Lark, Transformer


class NodeType(Enum):
    Ident = 0
    Lambda = 1
    Application = 2
    Assignment = 3
    Undef = 4
    Import = 5



class LambdaTransformer(Transformer):
    lambda_ = lambda args: [NodeType.Lambda, args[0], args[1]]
    application = lambda args: [NodeType.Application, args[0], args[1]]
    ident = lambda args: [NodeType.Ident, str(args[0])]
    assignment = lambda args: [NodeType.Assignment, args[0], args[1]]
    undef = lambda args: [NodeType.Undef, args[0]]
    import_ = lambda args: [NodeType.Import, args[0]]


def expr_to_str(expr):
    if expr[0] == NodeType.Lambda:
        return "λ%s.%s" % (expr_to_str(expr[1]), expr_to_str(expr[2]))
    if expr[0] == NodeType.Application:
        return "%s %s" % (expr_to_str(expr[1]), expr_to_str(expr[2]))
    if expr[0] == NodeType.Ident:
        return expr[1]
    return ""


def apply(expr, var, value):
    if expr[0] == NodeType.Application:
        apply(expr[1], var, value)
        apply(expr[2], var, value)
    elif expr[0] == NodeType.Lambda:
        if (value[0] == NodeType.Ident) == (expr[1][1] == var[1]):
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


def eval_stmt(stmt):
    if len(stmt) == 0:
        return ""
    result = parser.parse(stmt)
    if result[0] == NodeType.Undef:
        del variables[result[1][1]]
    elif result[0] == NodeType.Import:
        with open("lib/" + result[1]) as lib_file:
            for line in lib_file.readlines():
                eval_stmt(line.replace("\n", ""))
    else:
        reduce(result)
        return expr_to_str(result)
    return ""


parser = Lark.open("grammar.lark", parser="lalr", transformer=LambdaTransformer)

variables = {}

tests = [("x", "x"), ("x y", "x y"), ("lambda x.y", "λx.y"),
         ("lambda x.lambda y.x y", "λx.λy.x y"), ("(lambda x.y x) z", "y z"),
         ("(lambda x.x x) lambda y.y", "λy.y")]
RUN_TESTS = True

def main():
    test_number = 0
    while True:
        if RUN_TESTS and tests:
            is_test = True
            in_expr, expected = tests.pop(0)
            print(f"Test {test_number}> {in_expr}")
            test_number += 1
        else:
            is_test = False
            in_expr = input("> ")
            if in_expr.lower() in ("q", "quit", "exit"):
                break
        try:
            result = eval_stmt(in_expr)
            if result:
                print(result)
            if is_test:
                if result == expected:
                    print("\033[32mPassed ✓\033[0m")
                else:
                    print("\033[31mFailed X\033[0m")
                    print(f"Expected: {expected}")
        except RecursionError:
            print("\033[31mError: infinite loop\033[0m")
        except Exception as err:
            #print("\033[31mError: invalid syntax\033[0m")
            print(err)

if __name__ == "__main__":
    main()
