#include <cstdint>
#include <cassert>
typedef uint8_t u8;
typedef uint16_t u16;

enum ArithmeticTarget {	A, B, C, D, E, H, L, BC, DE, HL };

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

	u8& get(ArithmeticTarget r) {
		switch(r) {
			case A:	return a;
			case B:	return b;
			case C:	return c;
			case D:	return d;
			case E:	return e;
			case H:	return h;
			case L:	return l;
			default:	assert(false && "Invalid ArithimeticTarget in Regs::get");
		}
	}
	
	u16 get16(ArithmeticTarget r) {
		switch(r) {
			case BC:	return get_bc();
			case DE:	return get_de();
			case HL:	return get_hl();
			default:	assert(false && "Invalid ArithimeticTarget in Regs::get16");
		}
	}
};

enum Opcode {
	ADD, ADDHL, ADC, SUB, SBC
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
		case ADD:	regs.a = add(regs.get(((const OpTarget&)instruction).target));		break;
		case ADDHL:			 addhl(regs.get16(((const OpTarget&)instruction).target));	break;
		case ADC:	regs.a = adc(regs.get(((const OpTarget&)instruction).target));		break;
		case SUB:	regs.a = sub(regs.get(((const OpTarget&)instruction).target));		break;
		case SBC:	regs.a = sbc(regs.get(((const OpTarget&)instruction).target));		break;
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
	
	u8 adc(u8 value) {
		u8 new_value = regs.a + value + regs.f.carry;
		regs.f.zero = new_value == 0;
		regs.f.subtract = false;
		regs.f.half_carry = (regs.a & 0xf) + (value & 0xf) + regs.f.carry > 0xf;
		regs.f.carry = ((u16)regs.a + (u16)value + regs.f.carry) & 0x100;
		return new_value;
	}

	u8 sub(u8 value) {
		u8 new_value = regs.a - value;
		regs.f.zero = new_value == 0;
		regs.f.subtract = true;
		regs.f.carry = value > regs.a;
		regs.f.half_carry = (value & 0xf) > (regs.a & 0xf);
		return new_value;
	}	
	
	u8 sbc(u8 value) {
		u8 new_value = regs.a - value + regs.f.carry;
		regs.f.zero = new_value == 0;
		regs.f.subtract = true;
		regs.f.half_carry = (value & 0xf) > (regs.a & 0xf) + regs.f.carry;
		regs.f.carry = value > regs.a + regs.f.carry;
		return new_value;
	}

	u8 and(u8 value) {
		regs.f.zero = !(regs.a & value);
		regs.f.subtract = false;
		regs.f.carry = false;
		regs.f.half_carry = true;
	}
};