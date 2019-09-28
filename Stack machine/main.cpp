#include <cstdint>
#include <stddef.h>
#include <stdlib.h>
#include <iostream>

constexpr int32_t program[] {
	0x00000001, 10,
	0x00000007,
	0x00000009,
	0x00000012,
	0x00000007,
	0x0000000e, 2,
	0x00000000,
};

constexpr size_t stackSize = 1024;
size_t sp = 0;
size_t ip = 0;

class {
	int32_t data[stackSize];
public:
	int32_t& operator[](size_t index) { return data[index]; }
	void Push(const int32_t& v) { data[sp++] = v; }
	int32_t Pop() { return data[--sp]; }
	int32_t& Top() { return data[sp - 1]; }
} stack;



void hlt() { exit(0); }
void ldc() { stack.Push(program[ip + 1]);	ip += 2; }
void add() { stack.Push(stack.Pop() + stack.Pop());									ip++; }
void sub() { stack.Push(stack.Pop() - stack.Pop());									ip++; }
void mul() { stack.Push(stack.Pop() * stack.Pop());									ip++; }
void div() { stack.Push(stack.Pop() / stack.Pop());									ip++; }
void pop() { stack.Pop();															ip++; }
void dup() { stack.Push(stack.Top());												ip++; }
void swp() { stack[sp - 1] ^= stack[sp - 2] ^= stack[sp - 1] ^= stack[sp - 2];		ip++; }
void dsp() { std::cout << stack.Pop() << '\n';										ip++; }
void jmp() { ip = program[ip + 1]; }
void cal() {
	stack.Push(ip);
	ip = program[ip + 1];
}
void ret() { ip = stack.Pop() + 1; }
void jez() { if(stack.Pop() == 0)	ip = program[ip + 1];	else	ip += 2; }
void jnz() { if(stack.Pop() != 0)	ip = program[ip + 1];	else	ip += 2; }
void jgz() { if(stack.Pop() > 0)	ip = program[ip + 1];	else	ip += 2; }
void jlz() { if(stack.Pop() < 0)	ip = program[ip + 1];	else	ip += 2; }
void inc() { stack.Top()++;															ip++; }
void dec() { stack.Top()--;															ip++; }
void shl() { stack.Top() <<= 1;														ip++; }
void shr() { stack.Top() >>= 1;														ip++; }

constexpr void (*functions[])() {
	hlt, ldc, add, sub, mul, div, pop, dup, swp, dsp, jmp, cal, ret, jez, jnz, jgz, jlz, inc, dec, shl, shr
};



int main() {
	while(ip < sizeof(program) / sizeof(*program)) {
		functions[program[ip]]();
	}
	return 0;
}