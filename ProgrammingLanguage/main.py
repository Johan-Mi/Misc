#!/usr/bin/env python3

from enum import Enum
from operator import add, sub, mul, truediv as div, mod, eq, ne, gt, lt, ge, le
from lark import Lark, Transformer


class NodeType(Enum):
    Number, Var, Ident, Stmts, String, \
    Print, \
    Add, Sub, Mul, Div, Mod, Neg, \
    Eq, Ne, Gt, Lt, Ge, Le, \
    AbsAssign, PlusEq, MinEq, TimesEq, DivEq, \
    = range(23)


class AstTransformer(Transformer):
    @staticmethod
    def _number(args):
        num = str(args[0])
        return [NodeType.Number, float(num) if '.' in num else int(num)]

    @staticmethod
    def _string(args):
        return [NodeType.String, str(args[0][1:-1])]

    @staticmethod
    def _ident(args):
        return [NodeType.Ident, str(args[0])]

    @staticmethod
    def _add(args):
        return [NodeType.Add, args]

    @staticmethod
    def _sub(args):
        return [NodeType.Sub, args]

    @staticmethod
    def _mul(args):
        return [NodeType.Mul, args]

    @staticmethod
    def _div(args):
        return [NodeType.Div, args]

    @staticmethod
    def _mod(args):
        return [NodeType.Mod, args]

    @staticmethod
    def _neg(args):
        return [NodeType.Neg, args]

    @staticmethod
    def _print_stmt(args):
        return [NodeType.Print, args]

    @staticmethod
    def _stmts(args):
        return [NodeType.Stmts, args]

    @staticmethod
    def _abs_assign(args):
        return [NodeType.AbsAssign, [args[0][1], args[1]]]

    @staticmethod
    def _pluseq(args):
        return [NodeType.PlusEq, [args[0][1], args[1]]]

    @staticmethod
    def _mineq(args):
        return [NodeType.MinEq, [args[0][1], args[1]]]

    @staticmethod
    def _timeseq(args):
        return [NodeType.TimesEq, [args[0][1], args[1]]]

    @staticmethod
    def _diveq(args):
        return [NodeType.DivEq, [args[0][1], args[1]]]

    @staticmethod
    def _var(args):
        return [NodeType.Var, args[0][1]]

    @staticmethod
    def _eq(args):
        return [NodeType.Eq, args]

    @staticmethod
    def _ne(args):
        return [NodeType.Ne, args]

    @staticmethod
    def _gt(args):
        return [NodeType.Gt, args]

    @staticmethod
    def _lt(args):
        return [NodeType.Lt, args]

    @staticmethod
    def _ge(args):
        return [NodeType.Ge, args]

    @staticmethod
    def _le(args):
        return [NodeType.Le, args]


def eval_ast(ast, variables):
    def gen_binop(operator):
        return lambda: operator(eval_ast(ast[1][0], variables),
                                eval_ast(ast[1][1], variables))

    if ast[0] == NodeType.Stmts:
        return [eval_ast(s, variables) for s in ast[1]][-1]
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
        return -eval_ast(ast[1][0], variables)
    if ast[0] == NodeType.Print:
        return print(eval_ast(ast[1][0], variables))
    if ast[0] == NodeType.Var:
        return variables[ast[1]]
    if ast[0] == NodeType.AbsAssign:
        variables[ast[1][0]] = eval_ast(ast[1][1], variables)
        return variables[ast[1][0]]
    if ast[0] == NodeType.PlusEq:
        variables[ast[1][0]] += eval_ast(ast[1][1], variables)
        return variables[ast[1][0]]
    if ast[0] == NodeType.MinEq:
        variables[ast[1][0]] -= eval_ast(ast[1][1], variables)
        return variables[ast[1][0]]
    if ast[0] == NodeType.TimesEq:
        variables[ast[1][0]] *= eval_ast(ast[1][1], variables)
        return variables[ast[1][0]]
    if ast[0] == NodeType.DivEq:
        variables[ast[1][0]] /= eval_ast(ast[1][1], variables)
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


def main():
    parser = Lark.open("grammar.lark",
                       parser='lalr',
                       transformer=AstTransformer)

    variables = {}

    while True:
        try:
            in_expr = input('> ')
            if in_expr:
                result = parser.parse(in_expr)
                #print(result)
                eval_ast(result, variables)
        except KeyboardInterrupt:
            print()
        except EOFError:
            break
        except Exception as e:
            print(e)


if __name__ == "__main__":
    main()
