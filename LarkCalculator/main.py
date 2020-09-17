#!/usr/bin/env python3
"""Reads mathematical expressions from stdin and evaluates them."""

from lark import Lark, Transformer


class CalcTransformer(Transformer):  # pylint: disable=too-few-public-methods
    """Transformer for the parser."""
    @staticmethod
    def _num(args):
        return float(args[0])

    @staticmethod
    def _add(args):
        return float(args[0]) + float(args[1])

    @staticmethod
    def _sub(args):
        return float(args[0]) - float(args[1])

    @staticmethod
    def _mul(args):
        return float(args[0]) * float(args[1])

    @staticmethod
    def _div(args):
        return float(args[0]) / float(args[1])

    @staticmethod
    def _negate(args):
        return -args[0]


def main():
    """Creates a parser and uses it to evaluate stdin."""
    parser = Lark.open("grammar.lark",
                       parser='lalr',
                       transformer=CalcTransformer())

    try:
        result = parser.parse(input('> '))
        if result == int(result):
            result = int(result)
        print(result)
    except ZeroDivisionError:
        print('Tried to divide by zero!')
    except:
        print('Syntax error!')


if __name__ == "__main__":
    main()
