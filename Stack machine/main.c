#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

enum Opcode { HLT, LDC, ADD, SUB, MUL, DIV, POP, DUP, SWP, DSP, JMP, JSR, RET, JEZ, JNZ, JGZ, JLZ, INC, DEC, SHL, SHR };

const int32_t program[] = {
	LDC, 10,
	DUP,
	DSP,
	DEC,
	DUP,
	JGZ, 2,
	HLT
};

size_t sp = 0;
size_t ip = 0;
int32_t stack[1024];

void stackPush(const int32_t v) {
	stack[sp++] = v;
}

int32_t stackPop() {
	return stack[--sp];
}

int32_t stackTop() {
	return stack[sp - 1];
}

void hlt() { exit(0); }
void ldc() { stackPush(program[++ip]);											ip++; }
void add() { stackPush(stackPop() + stackPop());								ip++; }
void sub() { stackPush(stackPop() - stackPop());								ip++; }
void mul() { stackPush(stackPop() * stackPop());								ip++; }
void dv_() { stackPush(stackPop() / stackPop());								ip++; }
void pop() { stackPop();														ip++; }
void dup() { stackPush(stackTop());												ip++; }
void swp() { stack[sp - 1] ^= stack[sp - 2] ^= stack[sp - 1] ^= stack[sp - 2];	ip++; }
void dsp() { printf("%d\n", stackPop());										ip++; }
void jmp() { ip = program[ip + 1]; }
void jsr() { stackPush(ip);	ip = program[ip + 1]; }
void ret() { ip = stackPop() + 1; }
void jez() { ip = stackPop()		? ip + 2 : program[ip + 1]; }
void jnz() { ip = stackPop()		? program[ip + 1] : ip + 2; }
void jgz() { ip = (stackPop() > 0)	? program[ip + 1] : ip + 2; }
void jlz() { ip = (stackPop() < 0)	? program[ip + 1] : ip + 2; }
void inc() { stackPush(stackPop() + 1);											ip++; }
void dec() { stackPush(stackPop() - 1);											ip++; }
void shl() { stackPush(stackPop() << 1);										ip++; }
void shr() { stackPush(stackPop() >> 1);										ip++; }

void (*const functions[])() = { [HLT] = hlt, [LDC] = ldc, [ADD] = add, [SUB] = sub, [MUL] = mul, [DIV] = dv_, [POP] = pop, [DUP] = dup, [SWP] = swp, [DSP] = dsp, [JMP] = jmp, [JSR] = jsr, [RET] = ret, [JEZ] = jez, [JNZ] = jnz, [JGZ] = jgz, [JLZ] = jlz, [INC] = inc, [DEC] = dec, [SHL] = shl, [SHR] = shr };

int main(void) {
	while(ip < sizeof(program) / sizeof(*program))
		functions[program[ip]]();
	return EXIT_SUCCESS;
}
