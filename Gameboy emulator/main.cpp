#include <cstdint>
#include <cassert>
typedef uint8_t u8;
typedef uint16_t u16;

struct Regs {
	u8 a, b, c, d, e;
	Flags f;
	u8 h, l; 

	u16 get_bc() { return (u16)b << 8 | c; }
	u16 get_de() { return (u16)d << 8 | e; }
	u16 get_hl() { return (u16)h << 8 | l; }

	u16 set_bc(u16 value) {
		b = value >> 8;
		c = value;
	}
	u16 set_de(u16 value) {
		d = value >> 8;
		e = value;
	}
	u16 set_hl(u16 value) {
		h = value >> 8;
		l = value;
	}
};

constexpr u8 zero_flag_byte_position = 7;
constexpr u8 subtract_flag_byte_position = 6;
constexpr u8 half_carry_flag_byte_position = 5;
constexpr u8 carry_flag_byte_position = 4;

struct Flags {
	bool zero, subtract, half_carry, carry;

	Flags(u8 byte) : zero(byte >> zero_flag_byte_position & 1),
					 subtract(byte >> subtract_flag_byte_position & 1),	
					 half_carry(byte >> half_carry_flag_byte_position & 1),
					 carry(byte >> carry_flag_byte_position & 1) {}

	operator int() { return zero << zero_flag_byte_position
						  | subtract << subtract_flag_byte_position
						  | half_carry << half_carry_flag_byte_position
						  | carry << carry_flag_byte_position; }	
};

enum ArithmeticTarget {
	A, B, C, D, E, H, L, BC, DE, HL
};

enum Opcode {
	ADD, ADDHL
};

struct Op {
	Opcode opcode;
};

struct OpTarget : Op {
	ArithmeticTarget target;
};

struct CPU {
	Regs regs;
	void execute(const Op& instruction) {
		switch(instruction.opcode) {
		case ADD:
			switch(((const OpTarget&)instruction).target) {
			case A:	regs.a = add(regs.a);	break;
			case B:	regs.a = add(regs.b);	break;
			case C:	regs.a = add(regs.c);	break;
			case D:	regs.a = add(regs.d);	break;
			case E:	regs.a = add(regs.e);	break;
			case H:	regs.a = add(regs.h);	break;
			case L:	regs.a = add(regs.l);	break;
			default:	assert(false && "Invalid target for ADD");
			}
			break;
		
		case ADDHL:
			switch(((const OpTarget&)instruction).target) {
			case BC:	addhl(regs.get_bc());	break;
			case DE:	addhl(regs.get_de());	break;
			case HL:	addhl(regs.get_hl());	break;
			default:	assert(false && "Invalid target for ADDHL");
			}
			break;
		}
	}

	u8 add(u8 value) {
		u8 new_value = regs.a + value;
		regs.f.zero = new_value == 0;
		regs.f.subtract = false;
		regs.f.carry = ((u16)regs.a + (u16)value) & 0x100;
		regs.f.half_carry = (regs.a & 0xf) + (value & 0xf) > 0xf;
		return new_value;
	}

	void addhl(u16 value) {
		u16 new_value = ((u16)regs.h << 8 | regs.l) + value;
		regs.f.zero = new_value == 0;
		regs.f.subtract = false;
		regs.f.carry = (((uint32_t)regs.h << 8 | regs.l) + value) & 0x10000;
		regs.f.half_carry = ((regs.h & 0xfff) << 8 | regs.l) + value & 0xfff > 0xfff;
		regs.h = new_value >> 8;
		regs.l = new_value;
	}
};