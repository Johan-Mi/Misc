#include <cstdint>
#include <stddef.h>

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

struct Expression {
	Expression* parent = nullptr;
	virtual void Eval() = 0;
};