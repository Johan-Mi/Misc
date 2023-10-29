#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s (name of brainfuck program)\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        perror(argv[1]);
        return 1;
    }

    fseek(fp, 0L, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    char *program = (char *)calloc(1, size + 1);
    if (!program) {
        fclose(fp);
        fputs("Memory allocation failed\n", stderr);
        return 1;
    }

    if (fread(program, size, 1, fp) != 1) {
        fclose(fp);
        free(program);
        fputs("Read failed\n", stderr);
        return 1;
    }

    fclose(fp);

    unsigned char memory[65536] = {0};
    unsigned int progCounter = 0;
    unsigned short memPos = 0;

    while (progCounter < size) {
        switch (program[progCounter]) {
        case '+':
            memory[memPos]++;
            progCounter++;
            break;
        case '-':
            memory[memPos]--;
            progCounter++;
            break;
        case '>':
            memPos++;
            progCounter++;
            break;
        case '<':
            memPos--;
            progCounter++;
            break;
        case '.':
            putchar(memory[memPos]);
            progCounter++;
            break;
        case ',':
            memory[memPos] = getchar();
            progCounter++;
            break;
        case '[':
            if (memory[memPos] == 0) {
                int bracketCount = 0;
                do {
                    if (program[progCounter] == '[') {
                        bracketCount++;
                    } else if (program[progCounter] == ']') {
                        bracketCount--;
                    }
                    progCounter++;
                } while (bracketCount);
            } else {
                progCounter++;
            }
            break;
        case ']': {
            int bracketCount = 0;
            do {
                if (program[progCounter] == '[') {
                    bracketCount++;
                } else if (program[progCounter] == ']') {
                    bracketCount--;
                }
                progCounter--;
            } while (bracketCount);
        }
            progCounter++;
            break;
        default:
            progCounter++;
            break;
        }
    }

    free(program);

    return EXIT_SUCCESS;
}
