#!/usr/bin/env python3

from lark import Lark, Transformer
from enum import Enum
from functools import partial

class NodeType(Enum):
    Number = 0
    Add = 1
    Sub = 2
    Mul = 3
    Div = 4
    Neg = 5
    Print = 6
    Stmts = 7
    Assignment = 8
    Ident = 9
    Var = 10
    Pluseq = 11
    Mineq = 12

grammar = '''
    ?start      : stmts
    ?stmts      : stmt+             -> stmts
    ?stmt       : expr ";"
                | assignment ";"
                | pluseq ";"
                | mineq ";"
                | print_stmt ";"
    ?expr       : sum
    ?assignment : ident "=" expr    -> assignment
    ?pluseq     : ident "+=" expr   -> pluseq
    ?mineq      : ident "-=" expr   -> mineq
    ?print_stmt : "print" expr      -> print_stmt
    ?sum        : product
                | sum "+" product   -> add
                | sum "-" product   -> sub
    ?product    : atom
                | product "*" atom  -> mul
                | product "/" atom  -> div
    ?atom       : NUMBER            -> number
                | "-" atom          -> neg
                | ident             -> var
                | "(" expr ")"
    ?ident      : NAME              -> ident

    %import common.CNAME -> NAME
    %import common.NUMBER
    %import common.WS_INLINE
    %ignore WS_INLINE
'''

class AstTransformer(Transformer):
    number = lambda args:  [NodeType.Number, float(args[0])]
    ident = lambda args:   [NodeType.Ident, str(args[0])]
    add = lambda args: [NodeType.Add, args]
    sub = lambda args: [NodeType.Sub, args]
    mul = lambda args: [NodeType.Mul, args]
    div = lambda args: [NodeType.Div, args]
    neg = lambda args: [NodeType.Neg, args]
    print_stmt = lambda args: [NodeType.Print, args]
    stmts = lambda args: [NodeType.Stmts, args]
    assignment = lambda args: [NodeType.Assignment, [args[0][1], args[1]]]
    pluseq = lambda args: [NodeType.Pluseq, [args[0][1], args[1]]]
    mineq = lambda args: [NodeType.Mineq, [args[0][1], args[1]]]
    var = lambda args: [NodeType.Var, args[0][1]]

parser = Lark(grammar, parser='lalr', transformer=AstTransformer);

variables = {}

def evalAst(ast):
    if ast[0] == NodeType.Stmts:
        for s in ast[1]:
            evalAst(s)
    if ast[0] == NodeType.Number:
        return ast[1]
    if ast[0] == NodeType.Add:
        return evalAst(ast[1][0]) + evalAst(ast[1][1])
    if ast[0] == NodeType.Sub:
        return evalAst(ast[1][0]) - evalAst(ast[1][1])
    if ast[0] == NodeType.Mul:
        return evalAst(ast[1][0]) * evalAst(ast[1][1])
    if ast[0] == NodeType.Div:
        return evalAst(ast[1][0]) / evalAst(ast[1][1])
    if ast[0] == NodeType.Neg:
        return -evalAst(ast[1][0])
    if ast[0] == NodeType.Print:
        return print(evalAst(ast[1][0]))
    if ast[0] == NodeType.Var:
        if ast[1] in variables:
            return variables[ast[1]]
    if ast[0] == NodeType.Assignment:
        variables[ast[1][0]] = evalAst(ast[1][1])
    if ast[0] == NodeType.Pluseq:
        variables[ast[1][0]] += evalAst(ast[1][1])
    if ast[0] == NodeType.Mineq:
        variables[ast[1][0]] -= evalAst(ast[1][1])

while True:
    try:
        inExpr = input('> ')
        if inExpr:
            result = parser.parse(inExpr)
            #print(result)
            evalAst(result)
    except KeyboardInterrupt:
        print()
    except EOFError:
        break
    except Exception as e:
        print(e)
