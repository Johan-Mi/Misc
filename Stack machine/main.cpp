#include <cstdint>
#include <stddef.h>
#include <stdlib.h>

constexpr  size_t stackSize = 1024;

enum struct Type {
	i32, u32, bol, flt, dbl
};

struct Value {
	Type type;
	union {
		int32_t i32;
		uint32_t u32;
		bool bol;
		float flt;
		double dbl;
	};

	Value(int32_t v)	: type(Type::i32), i32(v) {}
	Value(uint32_t v)	: type(Type::u32), u32(v) {}
	Value(bool v)		: type(Type::bol), bol(v) {}
	Value(float v)		: type(Type::flt), flt(v) {}
	Value(double v)		: type(Type::dbl), dbl(v) {}
};

size_t sp = 0;
size_t ip = 0;

class {
	Value data[stackSize];
public:
	Value& operator[](size_t index) { return data[index]; }
	void Push(const Value& v) { data[sp++] = v; }
	Value Pop() { return data[--sp]; }
} stack;



void hlt() { exit(0); }

#define LD_CONST(NAME, TYPE) void NAME##_ld_const() { stack.Push(Value((TYPE)program[++sp]));	sp += sizeof(TYPE); }
LD_CONST(i32, int32_t)
LD_CONST(u32, uint32_t)
LD_CONST(bol, bool)
LD_CONST(flt, float)
LD_CONST(dbl, double)
#undef LD_CONST

#define MKBOP_1(TYPENAME, TYPE, OPNAME, OP) void TYPENAME##_##OPNAME() { stack.Push(stack.Pop().TYPENAME OP stack.Pop().TYPENAME); }
#define MKBOP(OPNAME, OP) \
MKBOP_1(i32, int32_t, OPNAME, OP) \
MKBOP_1(u32, uint32_t, OPNAME, OP) \
MKBOP_1(bol, bool, OPNAME, OP) \
MKBOP_1(flt, float, OPNAME, OP) \
MKBOP_1(dbl, double, OPNAME, OP)

MKBOP(add, +)
MKBOP(sub, -)
MKBOP(mul, *)
MKBOP(div, /)
#undef MKBOP_1
#undef MKBOP



void(*functions[])() {
	hlt, 
	i32_ld_const, u32_ld_const, bol_ld_const, flt_ld_const, dbl_ld_const,
	i32_add, u32_add, bol_add, flt_add, dbl_add,
	i32_sub, u32_sub, bol_sub, flt_sub, dbl_sub,
	i32_mul, u32_mul, bol_mul, flt_mul, dbl_mul,
	i32_div, u32_div, bol_div, flt_div, dbl_div,
};

constexpr uint32_t program[] {
	0x0
};

int main() {
	while(ip < sizeof(program)) {
		functions[program[ip]]();
	}
	return 0;
}