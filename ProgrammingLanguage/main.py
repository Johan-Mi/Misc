#!/usr/bin/env python3

from lark import Lark, Transformer
from enum import Enum
from operator import add, sub, mul, truediv as div, mod, eq, ne, gt, lt, ge, le

class NodeType(Enum):
    Number, Var, Ident, Stmts, String, \
    Print, \
    Add, Sub, Mul, Div, Mod, Neg, \
    Eq, Ne, Gt, Lt, Ge, Le, \
    AbsAssign, PlusEq, MinEq, TimesEq, DivEq, \
    = range(23)

grammar = '''
    ?start      : stmts
    ?stmts      : stmt+             -> stmts
    ?stmt       : expr ";"
                | print_stmt ";"
    ?expr       : sum
                | assignment
                | comparision

    ?assignment : abs_assign
                | pluseq
                | mineq
                | timeseq
                | diveq
    ?abs_assign : ident "="  expr   -> abs_assign
    ?pluseq     : ident "+=" expr   -> pluseq
    ?mineq      : ident "-=" expr   -> mineq
    ?timeseq    : ident "*=" expr   -> timeseq
    ?diveq      : ident "/=" expr   -> diveq

    ?comparision    : eq
                    | ne
                    | gt
                    | lt
                    | ge
                    | le
    ?eq : expr "==" expr    -> eq
    ?ne : expr "!=" expr    -> ne
    ?gt : expr ">"  expr    -> gt
    ?lt : expr "<"  expr    -> lt
    ?ge : expr ">=" expr    -> ge
    ?le : expr "<=" expr    -> le

    ?print_stmt : "print" expr      -> print_stmt

    ?sum        : product
                | sum "+" product   -> add
                | sum "-" product   -> sub
    ?product    : atom
                | product "*" atom  -> mul
                | product "/" atom  -> div
                | product "%" atom  -> mod
    ?atom       : NUMBER            -> number
                | "-" atom          -> neg
                | ident             -> var
                | "(" expr ")"
                | STRING            -> string

    ?ident      : NAME              -> ident

    %import common.CNAME            -> NAME
    %import common.NUMBER
    %import common.ESCAPED_STRING   -> STRING
    %import common.WS_INLINE
    %ignore WS_INLINE
'''

class AstTransformer(Transformer):
    def number(args):
        num = str(args[0])
        return [NodeType.Number, float(num) if '.' in num else int(num)]
    string      = lambda args: [NodeType.String,        str(args[0][1:-1])]
    ident       = lambda args: [NodeType.Ident,         str(args[0])]
    add         = lambda args: [NodeType.Add,           args]
    sub         = lambda args: [NodeType.Sub,           args]
    mul         = lambda args: [NodeType.Mul,           args]
    div         = lambda args: [NodeType.Div,           args]
    mod         = lambda args: [NodeType.Mod,           args]
    neg         = lambda args: [NodeType.Neg,           args]
    print_stmt  = lambda args: [NodeType.Print,         args]
    stmts       = lambda args: [NodeType.Stmts,         args]
    abs_assign  = lambda args: [NodeType.AbsAssign,     [args[0][1], args[1]]]
    pluseq      = lambda args: [NodeType.PlusEq,        [args[0][1], args[1]]]
    mineq       = lambda args: [NodeType.MinEq,         [args[0][1], args[1]]]
    timeseq     = lambda args: [NodeType.TimesEq,       [args[0][1], args[1]]]
    diveq       = lambda args: [NodeType.DivEq,         [args[0][1], args[1]]]
    var         = lambda args: [NodeType.Var,           args[0][1]]
    eq          = lambda args: [NodeType.Eq,            args]
    ne          = lambda args: [NodeType.Ne,            args]
    gt          = lambda args: [NodeType.Gt,            args]
    lt          = lambda args: [NodeType.Lt,            args]
    ge          = lambda args: [NodeType.Ge,            args]
    le          = lambda args: [NodeType.Le,            args]

def evalAst(ast):
    def gen_binop(operator):
        return lambda: operator(evalAst(ast[1][0]), evalAst(ast[1][1]))

    if ast[0] == NodeType.Stmts:
        return [evalAst(s) for s in ast[1]][-1]
    if ast[0] == NodeType.Number:
        return ast[1]
    if ast[0] == NodeType.String:
        return ast[1]
    if ast[0] == NodeType.Add:
        return gen_binop(add)()
    if ast[0] == NodeType.Sub:
        return gen_binop(sub)()
    if ast[0] == NodeType.Mul:
        return gen_binop(mul)()
    if ast[0] == NodeType.Div:
        return gen_binop(div)()
    if ast[0] == NodeType.Mod:
        return gen_binop(mod)()
    if ast[0] == NodeType.Neg:
        return -evalAst(ast[1][0])
    if ast[0] == NodeType.Print:
        return print(evalAst(ast[1][0]))
    if ast[0] == NodeType.Var:
        return variables[ast[1]]
    if ast[0] == NodeType.AbsAssign:
        variables[ast[1][0]] = evalAst(ast[1][1])
        return variables[ast[1][0]]
    if ast[0] == NodeType.PlusEq:
        variables[ast[1][0]] += evalAst(ast[1][1])
        return variables[ast[1][0]]
    if ast[0] == NodeType.MinEq:
        variables[ast[1][0]] -= evalAst(ast[1][1])
        return variables[ast[1][0]]
    if ast[0] == NodeType.TimesEq:
        variables[ast[1][0]] *= evalAst(ast[1][1])
        return variables[ast[1][0]]
    if ast[0] == NodeType.DivEq:
        variables[ast[1][0]] /= evalAst(ast[1][1])
        return variables[ast[1][0]]
    if ast[0] == NodeType.Eq:
        return gen_binop(eq)()
    if ast[0] == NodeType.Ne:
        return gen_binop(ne)()
    if ast[0] == NodeType.Gt:
        return gen_binop(gt)()
    if ast[0] == NodeType.Lt:
        return gen_binop(lt)()
    if ast[0] == NodeType.Ge:
        return gen_binop(ge)()
    if ast[0] == NodeType.Le:
        return gen_binop(le)()

parser = Lark(grammar, parser='lalr', transformer=AstTransformer);

variables = {}

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
