#include <cstdint>
#include <stddef.h>
#include <stdlib.h>

constexpr  size_t stackSize = 1024;

enum struct Type {
	i32, u32, bol, flt, dbl
};

struct Value {
	Type type;
	union value {
		int32_t i32;
		uint32_t u32;
		bool bol;
		float flt;
		double dbl;
	};
};

class {
	Value data[stackSize];
public:
	size_t sp = 0;
	Value& operator[](size_t index) { return data[index]; }
	void Push(const Value& v) { data[sp++] = v; }
	Value Pop() { return data[--sp]; }
} stack;



void hlt() { exit(0); }



void(*functions[])() {
	hlt
};

int main() {
	return 0;
}