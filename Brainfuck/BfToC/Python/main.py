#!/usr/bin/env python3

import re
from enum import Enum

class Token(Enum):
    Input, Output, Inc, Move, LoopBegin, LoopEnd, Set = range(7)

def main():
    with open('../program.bf') as prog_file:
        prog = re.sub(r'[^-\+,\.<>\[\]]', '', prog_file.read())
    prog = prog.replace('[-]', '0')
    output = []

    i = 0
    while i < len(prog):
        if prog[i] == '0':
            output.append((Token.Set, 0))
        elif prog[i] == ',':
            output.append((Token.Input, None))
        elif prog[i] == '.':
            output.append((Token.Output, None))
        elif prog[i] == '[':
            output.append((Token.LoopBegin, None))
        elif prog[i] == ']':
            output.append((Token.LoopEnd, None))
        elif prog[i] in '+-':
            change_amount = 0
            while prog[i] in '+-':
                change_amount += 1 if prog[i] == '+' else -1
                i += 1
            i -= 1
            output.append((Token.Inc, change_amount))
        elif prog[i] in '<>':
            change_amount = 0
            while prog[i] in '<>':
                change_amount += 1 if prog[i] == '>' else -1
                i += 1
            i -= 1
            output.append((Token.Move, change_amount))
        i += 1

    with open('../output.c', 'w') as out:
        out.write('#include <stdio.h>\n#include <stdlib.h>\n\nint main(void) {\n\tunsigned short ptr = 0;\n\tunsigned char memory[65536] = {0};\n\n')
        indentation = 1
        for token, value in output:
            if token == Token.Set:
                line = 'memory[ptr] = %d;' % value
            elif token == Token.Input:
                line = 'memory[ptr] = getchar();'
            elif token == Token.Output:
                line = 'putchar(memory[ptr]);'
            elif token == Token.Inc:
                if value == 1:
                    line = 'memory[ptr]++;'
                elif value == -1:
                    line = 'memory[ptr]--;'
                elif value > 0:
                    line = 'memory[ptr] += %d;' % value
                else:
                    line = 'memory[ptr] -= %d;' % -value
            elif token == Token.Move:
                if value == 1:
                    line = 'ptr++;'
                elif value == -1:
                    line = 'ptr--;'
                elif value > 0:
                    line = 'ptr += %d;' % value
                else:
                    line = 'ptr -= %d;' % -value
            elif token == Token.LoopBegin:
                line = 'while(memory[ptr]) {'
            elif token == Token.LoopEnd:
                line = '}'
                indentation -= 1

            out.write('\t' * indentation + line + '\n')

            if token == Token.LoopBegin:
                indentation += 1

        out.write('\n\treturn EXIT_SUCCESS;\n}')

if __name__ == "__main__":
    main()
