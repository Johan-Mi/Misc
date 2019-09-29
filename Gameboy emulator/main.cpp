#include <cstdint>
#include <cassert>
typedef uint8_t u8;
typedef uint16_t u16;
typedef int8_t i8;
typedef uint32_t u32;

enum ArithmeticTarget {	A, B, C, D, E, H, L, AF, BC, DE, HL };

struct Regs {
	union {
		struct {
			union {
				bool zero : 1;
				bool subtract : 1;
				bool half_carry : 1;
				bool carry : 1;
				u8 _ : 4;
			} f;
			u8 a;
		};
		u16 af;
	};
	union {
		struct { u8 c, b; };
		u16 bc = 0x0013;
	};
	union {
		struct { u8 e, d; };
		u16 de = 0x00d8;
	};
	union {
		struct { u8 l, h; };
		u16 hl = 0x014d;
	};
};

struct MemoryBus {
	u8 memory[0xffff];

	u8& read_byte(u16 address) {
		return memory[address];
	}
	
	u16 read_word(u16 address) {
		return (u16)memory[address]  | memory[address + 1] << 8;
	}
	
	u16 read_word_reverse(u16 address) {
		return (u16)memory[address] << 8  | memory[address + 1];
	}
	
	i8 read_signed_byte(u16 address) {
		return *(i8*)memory[address];
	}

	void write_byte(u16 address, u8 value) {
		memory[address] = value;
	}

	void write_word(u16 address, u16 value) {
		(*(u16*)memory[address]) = value;
	}
};

struct CPU {
	Regs regs;
	MemoryBus bus;
	u16 pc = 0x0100;
	u16 sp = 0xfffe;
	u8 cycles = 0;
	bool halted = false;
	bool stopped = false;
	enum { Off, On, Enabling, Disabling } interrupt_mode = On;

	void cycle(u8 c) { cycles += c - 1;	}

	void step() {
		if(!halted && !stopped) {
			if(interrupt_mode == Enabling)
				interrupt_mode = On;
			else if(interrupt_mode == Disabling)
				interrupt_mode = Off;
			
			if(!cycles) {
				u8 instruction_byte = bus.read_byte(pc);
				pc = execute(instruction_byte);
				cycles--;
			}
		}
	}

	u16 execute(u8 instruction) {
		switch(instruction) {
			/* NOP         */ case 0x00:	/*//////////////////////////////NOP//////////////////////////*/	pc++;	cycle(1);	break;
			/* LD BC,d16   */ case 0x01:	regs.bc = bus.read_word_reverse(pc + 1);						pc+=3;	cycle(1);	break;
			/* LD (BC),A   */ case 0x02:	bus.write_byte(regs.bc, regs.a);								pc++;	cycle(1);	break;
			/* INC BC      */ case 0x03:	regs.bc++;														pc++;	cycle(1);	break;
			/* INC B       */ case 0x04:	inc_byte(regs.b);												pc++;	cycle(1);	break;
			/* DEC B       */ case 0x05:	dec_byte(regs.b);												pc++;	cycle(1);	break;
			/* LD B,d8     */ case 0x06:	regs.b = bus.read_byte(pc + 1);									pc+=2;	cycle(1);	break;
			/* RLCA        */ case 0x07:	rlca();															pc++;	cycle(1);	break;
			/* LD (a16),SP */ case 0x08:	bus.write_byte(bus.read_word(pc + 1), sp);						pc+=2;	cycle(1);	break;
			/* ADD HL,BC   */ case 0x09:	add_hl(regs.bc);												pc++;	cycle(1);	break;
			/* LD A,(BC)   */ case 0x0a:	regs.a = bus.read_byte(regs.bc);								pc++;	cycle(1);	break;
			/* DEC BC      */ case 0x0b:	regs.bc--;														pc++;	cycle(1);	break;
			/* INC C       */ case 0x0c:	inc_byte(regs.c);												pc++;	cycle(1);	break;
			/* DEC C       */ case 0x0d:	dec_byte(regs.c);												pc++;	cycle(1);	break;
			/* LD C,d8     */ case 0x0e:	regs.c = bus.read_byte(pc + 1);									pc+=2;	cycle(1);	break;
			/* RRCA        */ case 0x0f:	rrca();															pc++;	cycle(1);	break;
			/* STOP 0      */ case 0x10:	stopped = true;													pc++;	cycle(1);	break;
			/* LD DE,d16   */ case 0x11:	regs.de = bus.read_word_reverse(pc + 1);						pc+=3;	cycle(1);	break;
			/* LD (DE),A   */ case 0x12:	bus.write_byte(regs.de, regs.a);								pc++;	cycle(1);	break;
			/* INC DE      */ case 0x13:	regs.de++;														pc++;	cycle(1);	break;
			/* INC D       */ case 0x14:	inc_byte(regs.d);												pc++;	cycle(1);	break;
			/* DEC D       */ case 0x15:	dec_byte(regs.d);												pc++;	cycle(1);	break;
			/* LD D,d8     */ case 0x16:	regs.d = bus.read_byte(pc + 1);									pc+=2;	cycle(1);	break;
			/* RLA         */ case 0x17:	rla();															pc++;	cycle(1);	break;
			/* JR r8       */ case 0x18:	pc += bus.read_signed_byte(pc + 1);										cycle(1);	break;
			/* ADD HL,DE   */ case 0x19:	add_hl(regs.de);												pc++;	cycle(1);	break;
			/* LD A,(DE)   */ case 0x1a:	regs.a = bus.read_byte(regs.de);								pc++;	cycle(1);	break;
			/* DEC DE      */ case 0x1b:	regs.de--;														pc++;	cycle(1);	break;
			/* INC E       */ case 0x1c:	inc_byte(regs.e);												pc++;	cycle(1);	break;
			/* DEC E       */ case 0x1d:	dec_byte(regs.e);												pc++;	cycle(1);	break;
			/* LD E,d8     */ case 0x1e:	regs.e = bus.read_byte(pc + 1);									pc+=2;	cycle(1);	break;
			/* RRA         */ case 0x1f:	rra();															pc++;	cycle(1);	break;
			/* JR NZ,r8    */ case 0x20:	if(regs.f.zero) pc += 2; else pc += bus.read_signed_byte(pc + 1);		cycle(1);	break;
			/* LD HL,d16   */ case 0x21:	regs.hl = bus.read_word_reverse(pc + 1);						pc+=3;	cycle(1);	break;
			/* LD (HL+),A  */ case 0x22:	bus.write_byte(regs.hl++, regs.a);								pc++;	cycle(1);	break;
			/* INC HL      */ case 0x23:	regs.hl++;														pc++;	cycle(1);	break;
			/* INC H       */ case 0x24:	inc_byte(regs.h);												pc++;	cycle(1);	break;
			/* DEC H       */ case 0x25:	dec_byte(regs.h);												pc++;	cycle(1);	break;
			/* LD H,d8     */ case 0x26:	regs.h = bus.read_byte(pc + 1);									pc+=2;	cycle(1);	break;
			/* DAA         */ case 0x27:	daa();															pc++;	cycle(1);	break;
			/* JR Z,r8     */ case 0x28:	if(regs.f.zero) pc += bus.read_signed_byte(pc + 1); else pc += 2;		cycle(1);	break;
			/* ADD HL,HL   */ case 0x29:	add_hl(regs.hl);												pc++;	cycle(1);	break;
			/* LD A,(HL+)  */ case 0x2a:	regs.a = bus.read_byte(regs.hl++);								pc++;	cycle(1);	break;
			/* DEC HL      */ case 0x2b:	regs.hl--;														pc++;	cycle(1);	break;
			/* INC L       */ case 0x2c:	inc_byte(regs.l);												pc++;	cycle(1);	break;
			/* DEC L       */ case 0x2d:	dec_byte(regs.l);												pc++;	cycle(1);	break;
			/* LD L,d8     */ case 0x2e:	regs.l = bus.read_byte(pc + 1);									pc+=2;	cycle(1);	break;
			/* CPL         */ case 0x2f:	cpl();															pc++;	cycle(1);	break;
			/* JR NC,r8    */ case 0x30:	if(regs.f.carry) pc += 2; else pc += bus.read_signed_byte(pc + 1);		cycle(1);	break;
			/* LD SP,d16   */ case 0x31:	sp = bus.read_word_reverse(pc + 1);								pc+=3;	cycle(1);	break;
			/* LD (HL-),A  */ case 0x32:	bus.write_byte(regs.hl--, regs.a);								pc++;	cycle(1);	break;
			/* INC SP      */ case 0x33:	sp++;															pc++;	cycle(1);	break;
			/* INC (HL)    */ case 0x34:	inc_byte(bus.read_byte(regs.hl));								pc++;	cycle(1);	break;
			/* DEC (HL)    */ case 0x35:	dec_byte(bus.read_byte(regs.hl));								pc++;	cycle(1);	break;
			/* LD (HL),d8  */ case 0x36:	bus.write_byte(regs.hl, bus.read_byte(pc + 1));					pc+=2;	cycle(1);	break;
			/* SCF         */ case 0x37:	scf();															pc++;	cycle(1);	break;
			/* JR C,r8     */ case 0x38:	if(regs.f.carry) pc += bus.read_signed_byte(pc + 1); else pc += 2;		cycle(1);	break;
			/* ADD HL,SP   */ case 0x39:	add_hl(sp);														pc++;	cycle(1);	break;
			/* LD A,(HL-)  */ case 0x3a:	regs.a = bus.read_byte(regs.hl--);								pc++;	cycle(1);	break;
			/* DEC SP      */ case 0x3b:	sp--;															pc++;	cycle(1);	break;
			/* INC A       */ case 0x3c:	inc_byte(regs.a);												pc++;	cycle(1);	break;
			/* DEC A       */ case 0x3d:	dec_byte(regs.l);												pc++;	cycle(1);	break;
			/* LD A,d8     */ case 0x3e:	regs.a = bus.read_byte(pc + 1);									pc+=2;	cycle(1);	break;
			/* CCF         */ case 0x3f:	ccf();															pc++;	cycle(1);	break;
			/* LD B,B      */ case 0x40:	/*//////////////////////////////NOP//////////////////////////*/ pc++;	cycle(1);	break;
			/* LD B,C      */ case 0x41:	regs.b = regs.c;												pc++;	cycle(1);	break;
			/* LD B,D      */ case 0x42:	regs.b = regs.d;												pc++;	cycle(1);	break;
			/* LD B,E      */ case 0x43:	regs.b = regs.e;												pc++;	cycle(1);	break;
			/* LD B,H      */ case 0x44:	regs.b = regs.h;												pc++;	cycle(1);	break;
			/* LD B,L      */ case 0x45:	regs.b = regs.l;												pc++;	cycle(1);	break;
			/* LD B,(HL)   */ case 0x46:	regs.b = bus.read_byte(regs.hl);								pc++;	cycle(1);	break;
			/* LD B,A      */ case 0x47:	regs.b = regs.a;												pc++;	cycle(1);	break;
			/* LD C,B      */ case 0x48:	regs.c = regs.b;												pc++;	cycle(1);	break;
			/* LD C,C      */ case 0x49:	/*//////////////////////////////NOP//////////////////////////*/ pc++;	cycle(1);	break;
			/* LD C,D      */ case 0x4a:	regs.c = regs.d;												pc++;	cycle(1);	break;
			/* LD C,E      */ case 0x4b:	regs.c = regs.e;												pc++;	cycle(1);	break;
			/* LD C,H      */ case 0x4c:	regs.c = regs.h;												pc++;	cycle(1);	break;
			/* LD C,L      */ case 0x4d:	regs.c = regs.l;												pc++;	cycle(1);	break;
			/* LD C,(HL)   */ case 0x4e:	regs.c = bus.read_byte(regs.hl);								pc++;	cycle(1);	break;
			/* LD C,A      */ case 0x4f:	regs.c = regs.a;												pc++;	cycle(1);	break;
			/* LD D,B      */ case 0x50:	regs.d = regs.b;												pc++;	cycle(1);	break;
			/* LD D,C      */ case 0x51:	regs.d = regs.c;												pc++;	cycle(1);	break;
			/* LD D,D      */ case 0x52:	/*//////////////////////////////NOP//////////////////////////*/	pc++;	cycle(1);	break;
			/* LD D,E      */ case 0x53:	regs.d = regs.e;												pc++;	cycle(1);	break;
			/* LD D,H      */ case 0x54:	regs.d = regs.h;												pc++;	cycle(1);	break;
			/* LD D,L      */ case 0x55:	regs.d = regs.l;												pc++;	cycle(1);	break;
			/* LD D,(HL)   */ case 0x56:	regs.d = bus.read_byte(regs.hl);								pc++;	cycle(1);	break;
			/* LD D,A      */ case 0x57:	regs.d = regs.a;												pc++;	cycle(1);	break;
			/* LD E,B      */ case 0x58:	regs.e = regs.b;												pc++;	cycle(1);	break;
			/* LD E,C      */ case 0x59:	regs.e = regs.c;												pc++;	cycle(1);	break;
			/* LD E,D      */ case 0x5a:	regs.e = regs.d;												pc++;	cycle(1);	break;
			/* LD E,E      */ case 0x5b:	/*//////////////////////////////NOP//////////////////////////*/	pc++;	cycle(1);	break;
			/* LD E,H      */ case 0x5c:	regs.e = regs.h;												pc++;	cycle(1);	break;
			/* LD E,L      */ case 0x5d:	regs.e = regs.l;												pc++;	cycle(1);	break;
			/* LD E,(HL)   */ case 0x5e:	regs.e = bus.read_byte(regs.hl);								pc++;	cycle(1);	break;
			/* LD E,A      */ case 0x5f:	regs.e = regs.a;												pc++;	cycle(1);	break;
			/* LD H,B      */ case 0x60:	regs.h = regs.b;												pc++;	cycle(1);	break;
			/* LD H,C      */ case 0x61:	regs.h = regs.c;												pc++;	cycle(1);	break;
			/* LD H,D      */ case 0x62:	regs.h = regs.d;												pc++;	cycle(1);	break;
			/* LD H,E      */ case 0x63:	regs.h = regs.e;												pc++;	cycle(1);	break;
			/* LD H,H      */ case 0x64:	regs.h = regs.h;												pc++;	cycle(1);	break;
			/* LD H,L      */ case 0x65:	regs.h = regs.l;												pc++;	cycle(1);	break;
			/* LD H,(HL)   */ case 0x66:	regs.h = bus.read_byte(regs.hl);								pc++;	cycle(1);	break;
			/* LD H,A      */ case 0x67:	regs.h = regs.a;												pc++;	cycle(1);	break;
			/* LD L,B      */ case 0x68:	regs.l = regs.b;												pc++;	cycle(1);	break;
			/* LD L,C      */ case 0x69:	regs.l = regs.c;												pc++;	cycle(1);	break;
			/* LD L,D      */ case 0x6a:	regs.l = regs.d;												pc++;	cycle(1);	break;
			/* LD L,E      */ case 0x6b:	regs.l = regs.e;												pc++;	cycle(1);	break;
			/* LD L,H      */ case 0x6c:	regs.l = regs.h;												pc++;	cycle(1);	break;
			/* LD L,L      */ case 0x6d:	/*//////////////////////////////NOP//////////////////////////*/ pc++;	cycle(1);	break;
			/* LD L,(HL)   */ case 0x6e:	regs.l = bus.read_byte(regs.hl);								pc++;	cycle(1);	break;
			/* LD L,A      */ case 0x6f:	regs.l = regs.a;												pc++;	cycle(1);	break;
			/* LD (HL),B   */ case 0x70:	bus.write_byte(regs.hl, regs.b);								pc++;	cycle(1);	break;
			/* LD (HL),C   */ case 0x71:	bus.write_byte(regs.hl, regs.c);								pc++;	cycle(1);	break;
			/* LD (HL),D   */ case 0x72:	bus.write_byte(regs.hl, regs.d);								pc++;	cycle(1);	break;
			/* LD (HL),E   */ case 0x73:	bus.write_byte(regs.hl, regs.e);								pc++;	cycle(1);	break;
			/* LD (HL),H   */ case 0x74:	bus.write_byte(regs.hl, regs.h);								pc++;	cycle(1);	break;
			/* LD (HL),L   */ case 0x75:	bus.write_byte(regs.hl, regs.l);								pc++;	cycle(1);	break;
			/* HALT        */ case 0x76:	halted = true;													pc++;	cycle(1);	break;
			/* LD (HL),A   */ case 0x77:	bus.write_byte(regs.hl, regs.a);								pc++;	cycle(1);	break;
			/* LD A,B      */ case 0x78:	regs.a = regs.b;												pc++;	cycle(1);	break;
			/* LD A,C      */ case 0x79:	regs.a = regs.c;												pc++;	cycle(1);	break;
			/* LD A,D      */ case 0x7a:	regs.a = regs.d;												pc++;	cycle(1);	break;
			/* LD A,E      */ case 0x7b:	regs.a = regs.e;												pc++;	cycle(1);	break;
			/* LD A,H      */ case 0x7c:	regs.a = regs.h;												pc++;	cycle(1);	break;
			/* LD A,L      */ case 0x7d:	regs.a = regs.l;												pc++;	cycle(1);	break;
			/* LD A,(HL)   */ case 0x7e:	regs.a = bus.read_byte(regs.hl);								pc++;	cycle(1);	break;
			/* LD A,A      */ case 0x7f:	/*//////////////////////////////NOP//////////////////////////*/ pc++;	cycle(1);	break;
			/* ADD A,B     */ case 0x80:	add_a(regs.b);													pc++;	cycle(1);	break;
			/* ADD A,C     */ case 0x81:	add_a(regs.c);													pc++;	cycle(1);	break;
			/* ADD A,D     */ case 0x82:	add_a(regs.d);													pc++;	cycle(1);	break;
			/* ADD A,E     */ case 0x83:	add_a(regs.e);													pc++;	cycle(1);	break;
			/* ADD A,H     */ case 0x84:	add_a(regs.h);													pc++;	cycle(1);	break;
			/* ADD A,L     */ case 0x85:	add_a(regs.l);													pc++;	cycle(1);	break;
			/* ADD A,(HL)  */ case 0x86:	add_a(bus.read_byte(regs.hl));									pc++;	cycle(1);	break;
			/* ADD A,A     */ case 0x87:	add_a(regs.a);													pc++;	cycle(1);	break;
			/* ADC A,B     */ case 0x88:	adc_a(regs.b);													pc++;	cycle(1);	break;
			/* ADC A,C     */ case 0x89:	adc_a(regs.c);													pc++;	cycle(1);	break;
			/* ADC A,D     */ case 0x8a:	adc_a(regs.d);													pc++;	cycle(1);	break;
			/* ADC A,E     */ case 0x8b:	adc_a(regs.e);													pc++;	cycle(1);	break;
			/* ADC A,H     */ case 0x8c:	adc_a(regs.h);													pc++;	cycle(1);	break;
			/* ADC A,L     */ case 0x8d:	adc_a(regs.l);													pc++;	cycle(1);	break;
			/* ADC A,(HL)  */ case 0x8e:	adc_a(bus.read_byte(regs.hl));									pc++;	cycle(1);	break;
			/* ADC A,A     */ case 0x8f:	adc_a(regs.a);													pc++;	cycle(1);	break;
			/* SUB B       */ case 0x90:	sub_a(regs.b);													pc++;	cycle(1);	break;
			/* SUB C       */ case 0x91:	sub_a(regs.c);													pc++;	cycle(1);	break;
			/* SUB D       */ case 0x92:	sub_a(regs.d);													pc++;	cycle(1);	break;
			/* SUB E       */ case 0x93:	sub_a(regs.e);													pc++;	cycle(1);	break;
			/* SUB H       */ case 0x94:	sub_a(regs.h);													pc++;	cycle(1);	break;
			/* SUB L       */ case 0x95:	sub_a(regs.l);													pc++;	cycle(1);	break;
			/* SUB (HL)    */ case 0x96:	sub_a(bus.read_byte(regs.hl));									pc++;	cycle(1);	break;
			/* SUB A       */ case 0x97:	sub_a(regs.a);													pc++;	cycle(1);	break;
			/* SBC A,B     */ case 0x98:	sbc_a(regs.b);													pc++;	cycle(1);	break;
			/* SBC A,C     */ case 0x99:	sbc_a(regs.c);													pc++;	cycle(1);	break;
			/* SBC A,D     */ case 0x9a:	sbc_a(regs.d);													pc++;	cycle(1);	break;
			/* SBC A,E     */ case 0x9b:	sbc_a(regs.e);													pc++;	cycle(1);	break;
			/* SBC A,H     */ case 0x9c:	sbc_a(regs.h);													pc++;	cycle(1);	break;
			/* SBC A,L     */ case 0x9d:	sbc_a(regs.l);													pc++;	cycle(1);	break;
			/* SBC A,(HL)  */ case 0x9e:	sbc_a(bus.read_byte(regs.hl));									pc++;	cycle(1);	break;
			/* SBC A,A     */ case 0x9f:	sbc_a(regs.a);													pc++;	cycle(1);	break;
			/* AND B       */ case 0xa0:	and_a(regs.b);													pc++;	cycle(1);	break;
			/* AND C       */ case 0xa1:	and_a(regs.c);													pc++;	cycle(1);	break;
			/* AND D       */ case 0xa2:	and_a(regs.d);													pc++;	cycle(1);	break;
			/* AND E       */ case 0xa3:	and_a(regs.e);													pc++;	cycle(1);	break;
			/* AND H       */ case 0xa4:	and_a(regs.h);													pc++;	cycle(1);	break;
			/* AND L       */ case 0xa5:	and_a(regs.l);													pc++;	cycle(1);	break;
			/* AND (HL)    */ case 0xa6:	and_a(bus.read_byte(regs.hl));									pc++;	cycle(1);	break;
			/* AND A       */ case 0xa7:	and_a(regs.a);													pc++;	cycle(1);	break;
			/* XOR B       */ case 0xa8:	xor_a(regs.b);													pc++;	cycle(1);	break;
			/* XOR C       */ case 0xa9:	xor_a(regs.c);													pc++;	cycle(1);	break;
			/* XOR D       */ case 0xaa:	xor_a(regs.d);													pc++;	cycle(1);	break;
			/* XOR E       */ case 0xab:	xor_a(regs.e);													pc++;	cycle(1);	break;
			/* XOR H       */ case 0xac:	xor_a(regs.h);													pc++;	cycle(1);	break;
			/* XOR L       */ case 0xad:	xor_a(regs.l);													pc++;	cycle(1);	break;
			/* XOR (HL)    */ case 0xae:	xor_a(bus.read_byte(regs.hl));									pc++;	cycle(1);	break;
			/* XOR A       */ case 0xaf:	xor_a(regs.a);													pc++;	cycle(1);	break;
			/* OR B        */ case 0xb0:	or_a(regs.b);													pc++;	cycle(1);	break;
			/* OR C        */ case 0xb1:	or_a(regs.c);													pc++;	cycle(1);	break;
			/* OR D        */ case 0xb2:	or_a(regs.d);													pc++;	cycle(1);	break;
			/* OR E        */ case 0xb3:	or_a(regs.e);													pc++;	cycle(1);	break;
			/* OR H        */ case 0xb4:	or_a(regs.h);													pc++;	cycle(1);	break;
			/* OR L        */ case 0xb5:	or_a(regs.l);													pc++;	cycle(1);	break;
			/* OR (HL)     */ case 0xb6:	or_a(bus.read_byte(regs.hl));									pc++;	cycle(1);	break;
			/* OR A        */ case 0xb7:	or_a(regs.a);													pc++;	cycle(1);	break;
			/* CP B        */ case 0xb8:	cp(regs.b);														pc++;	cycle(1);	break;
			/* CP C        */ case 0xb9:	cp(regs.c);														pc++;	cycle(1);	break;
			/* CP D        */ case 0xba:	cp(regs.d);														pc++;	cycle(1);	break;
			/* CP E        */ case 0xbb:	cp(regs.e);														pc++;	cycle(1);	break;
			/* CP H        */ case 0xbc:	cp(regs.h);														pc++;	cycle(1);	break;
			/* CP L        */ case 0xbd:	cp(regs.l);														pc++;	cycle(1);	break;
			/* CP (HL)     */ case 0xbe:	cp(bus.read_byte(regs.hl));										pc++;	cycle(1);	break;
			/* CP A        */ case 0xbf:	cp(regs.a);														pc++;	cycle(1);	break;
			/* RET NZ      */ case 0xc0:	if(regs.f.zero) pc++; else pc = pop();									cycle(1);	break;
			/* POP BC      */ case 0xc1:	regs.bc = pop();												pc++;	cycle(1);	break;
			/* JP NZ,a16   */ case 0xc2:	if(regs.f.zero) pc += 3; else pc = bus.read_word(pc + 1);				cycle(1);	break;
			/* JP a16      */ case 0xc3:	pc = bus.read_word(pc + 1);												cycle(1);	break;
			/* CALL NZ,a16 */ case 0xc4:	if(regs.f.zero) pc += 3; else call();									cycle(1);	break;
			/* PUSH BC     */ case 0xc5:	push(regs.bc);													pc++;	cycle(1);	break;
			/* ADD A,d8    */ case 0xc6:	add_a(bus.read_byte(pc + 1));									pc+=2;	cycle(1);	break;
			/* RST 00H     */ case 0xc7:	push(pc);														pc=0;	cycle(1);	break;
			/* RET Z       */ case 0xc8:	if(regs.f.zero) pc = pop(); else pc++;									cycle(1);	break;
			/* RET         */ case 0xc9:	pc = pop();																cycle(1);	break;
			/* JP Z,a16    */ case 0xca:	if(regs.f.zero) pc = bus.read_word(pc + 1); else pc += 3;				cycle(1);	break;
			/* Prefix      */			 /*///////////////////////////////Prefix/////////////////////////*/
			/* CALL Z,a16  */ case 0xcc:	if(regs.f.zero) call(); else pc += 3;									cycle(1);	break;
			/* CALL a16    */ case 0xcd:	call();																	cycle(1);	break;
			/* ADC A,d8    */ case 0xce:	adc_a(bus.read_byte(pc + 1));									pc+=2;	cycle(1);	break;
			/* RST 08H     */ case 0xcf:	push(pc);														pc=8;	cycle(1);	break;
			/* RET NC      */ case 0xd0:	if(regs.f.carry) pc++; else pc = pop();									cycle(1);	break;
			/* POP DE      */ case 0xd1:	regs.de = pop();												pc++;	cycle(1);	break;
			/* JP NC,a16   */ case 0xd2:	if(regs.f.carry) pc += 3; else pc = bus.read_word(pc + 1);				cycle(1);	break;
			/* Invalid     */ case 0xd3:	/*///////////////////////////Invalid/////////////////////////*/ pc++;				break;
			/* CALL NC,a16 */ case 0xd4:	if(regs.f.carry) pc += 3; else call();									cycle(1);	break;
			/* PUSH DE     */ case 0xd5:	push(regs.de);													pc++;	cycle(1);	break;
			/* SUB d8      */ case 0xd6:	sub_a(bus.read_byte(pc + 1));									pc++;	cycle(1);	break;
			/* RST 10H     */ case 0xd7:	push(pc);														pc=16;	cycle(1);	break;
			/* RET C       */ case 0xd8:	if(regs.f.carry) pc = pop(); else pc++;									cycle(1);	break;
			/* RETI        */ case 0xd9:	pc = pop();	interrupt_mode = Enabling;									cycle(1);	break;
			/* JP C,a16    */ case 0xda:	if(regs.f.zero) pc = bus.read_word(pc + 1); else pc += 3;				cycle(1);	break;
			/* Invalid     */ case 0xdb:	/*///////////////////////////Invalid/////////////////////////*/ pc++;				break;
			/* CALL C,a16  */ case 0xdc:	if(regs.f.carry) call(); else pc += 3;									cycle(1);	break;
			/* Invalid     */ case 0xdd:	/*///////////////////////////Invalid/////////////////////////*/ pc++;				break;
			/* SBC A,d8    */ case 0xde:	sub_a(bus.read_byte(pc + 1));									pc+=2;	cycle(1);	break;
			/* RST 18H     */ case 0xdf:	push(pc);														pc=24;	cycle(1);	break;
			/* LDH (a8),A  */ case 0xe0:	bus.write_byte(0xff | bus.read_byte(pc + 1), regs.a);			pc+=2;	cycle(1);	break;
			/* POP HL      */ case 0xe1:	regs.hl = pop();												pc++;	cycle(1);	break;
			/* LD (C),A    */ case 0xe2:	bus.write_byte(regs.c, regs.a);									pc++;	cycle(1);	break;
			/* Invalid     */ case 0xe3:	/*///////////////////////////Invalid/////////////////////////*/ pc++;				break;
			/* Invalid     */ case 0xe4:	/*///////////////////////////Invalid/////////////////////////*/ pc++;				break;
			/* PUSH HL     */ case 0xe5:	push(regs.hl);													pc++;	cycle(1);	break;
			/* AND d8      */ case 0xe6:	and_a(bus.read_byte(pc + 1));									pc+=2;	cycle(1);	break;
			/* RST 20H     */ case 0xe7:	push(pc);														pc=32;	cycle(1);	break;
			/* ADD SP,r8   */ case 0xe8:	add_sp(bus.read_byte(pc + 1));									pc+=2;	cycle(1);	break;
			/* JP (HL)     */ case 0xe9:	pc = bus.read_word(regs.hl);											cycle(1);	break;
			/* LD (a16),A  */ case 0xea:	bus.write_byte(bus.read_word(pc + 1), regs.a);					pc+=3;	cycle(1);	break;
			/* Invalid     */ case 0xeb:	/*///////////////////////////Invalid/////////////////////////*/ pc++;				break;
			/* Invalid     */ case 0xec:	/*///////////////////////////Invalid/////////////////////////*/ pc++;				break;
			/* Invalid     */ case 0xed:	/*///////////////////////////Invalid/////////////////////////*/ pc++;				break;
			/* XOR d8      */ case 0xee:	xor_a(bus.read_byte(pc + 1));									pc+=2;	cycle(1);	break;
			/* RST 28H     */ case 0xef:	push(pc);														pc=40;	cycle(1);	break;
			/* LDH A,(a8)  */ case 0xf0:	regs.a = bus.read_byte(0xff | bus.read_byte(pc + 1));			pc+=2;	cycle(1);	break;
			/* POP AF      */ case 0xf1:	regs.af = pop();												pc++;	cycle(1);	break;
			/* LD A,(C)    */ case 0xf2:	regs.a = bus.read_byte(regs.c);									pc++;	cycle(1);	break;
			/* DI          */ case 0xf3:	interrupt_mode = Disabling;										pc++;	cycle(1);	break;
			/* Invalid     */ case 0xf4:	/*///////////////////////////Invalid/////////////////////////*/ pc++;				break;
			/* PUSH AF     */ case 0xf5:	push(regs.af);													pc++;	cycle(1);	break;
			/* OR d8       */ case 0xf6:	or_a(bus.read_byte(pc + 1));									pc++;	cycle(1);	break;
			/* RST 30H     */ case 0xf7:	push(pc);														pc=48;	cycle(1);	break;
			/* LD HL,SP+r8 */ case 0xf8:	ldhlspr8();														pc+=2;	cycle(1);	break;
			/* LD SP,HL    */ case 0xf9:	sp = regs.hl;													pc++;	cycle(1);	break;
			/* LD A,(a16)  */ case 0xfa:	regs.a = bus.read_byte(bus.read_word(pc + 1));					pc+=3;	cycle(1);	break;
			/* EI          */ case 0xfb:	interrupt_mode = Enabling;										pc++;	cycle(1);	break;
			/* Invalid     */ case 0xfc:	/*///////////////////////////Invalid/////////////////////////*/ pc++;				break;
			/* Invalid     */ case 0xfd:	/*///////////////////////////Invalid/////////////////////////*/ pc++;				break;
			/* CP d8       */ case 0xfe:	cp(bus.read_byte(pc + 1));										pc+=2;	cycle(1);	break;
			/* RST 38H     */ case 0xff:	push(pc);														pc=56;	cycle(1);	break;
		
						
			/* Prefix      */ case 0xcb: /* TODO: Prefix instructions */	break;
		}
	}

	void add_a(u8 value) {
		u8 new_value = regs.a + value;
		regs.f.zero = new_value == 0;
		regs.f.subtract = false;
		regs.f.carry = ((u16)regs.a + (u16)value) & 0x100;
		regs.f.half_carry = (regs.a & 0xf) + (value & 0xf) > 0xf;
		regs.a = new_value;
	}
	
	void add_hl(u16 value) {
		u16 new_value = regs.hl + value;
		regs.f.zero = new_value == 0;
		regs.f.subtract = false;
		regs.f.carry = ((u32)regs.hl + (u32)value) & 0x10000;
		regs.f.half_carry = (regs.hl & 0xff) + (value & 0xff) > 0xff;
		regs.hl = new_value;
	}
	
	void add_sp(u16 value) {
		u16 new_value = sp + value;
		regs.f.zero = new_value == 0;
		regs.f.subtract = false;
		regs.f.carry = ((u32)sp + (u32)value) & 0x10000;
		regs.f.half_carry = (sp & 0xff) + (value & 0xff) > 0xff;
		sp = new_value;
	}
	
	void adc_a(u8 value) {
		u8 new_value = regs.a + value + regs.f.carry;
		regs.f.zero = new_value == 0;
		regs.f.subtract = false;
		regs.f.half_carry = (regs.a & 0xf) + (value & 0xf) + regs.f.carry > 0xf;
		regs.f.carry = ((u16)regs.a + (u16)value + regs.f.carry) & 0x100;
		regs.a = new_value;
	}

	void sub_a(u8 value) {
		u8 new_value = regs.a - value;
		regs.f.zero = new_value == 0;
		regs.f.subtract = true;
		regs.f.carry = value > regs.a;
		regs.f.half_carry = (value & 0xf) > (regs.a & 0xf);
		regs.a = new_value;
	}	
	
	void cp(u8 value) {
		regs.f.zero = regs.a == value;
		regs.f.subtract = true;
		regs.f.carry = value > regs.a;
		regs.f.half_carry = (value & 0xf) > (regs.a & 0xf);
	}	
	
	void sbc_a(u8 value) {
		u8 new_value = regs.a - value - regs.f.carry;
		regs.f.zero = new_value == 0;
		regs.f.subtract = true;
		regs.f.half_carry = (value & 0xf) > (regs.a & 0xf) - regs.f.carry;
		regs.f.carry = value > regs.a - regs.f.carry;
		regs.a = new_value;
	}

	void and_a(u8 value) {
		regs.a &= value;
		regs.f.zero = !regs.a;
		regs.f.subtract = false;
		regs.f.half_carry = true;
		regs.f.carry = false;
	}
	
	void xor_a(u8 value) {
		regs.a ^= value;
		regs.f.zero = !regs.a;
		regs.f.subtract = false;
		regs.f.half_carry = false;
		regs.f.carry = false;
	}
	
	void or_a(u8 value) {
		regs.a |= value;
		regs.f.zero = !regs.a;
		regs.f.subtract = false;
		regs.f.half_carry = false;
		regs.f.carry = false;
	}

	void rlca() {
		regs.f.subtract = false;
		regs.f.half_carry = false;
		regs.f.carry = regs.a >> 7;
		regs.a <<= 1;
		regs.f.zero = regs.a == 0;
	}
	
	void rrca() {
		regs.f.subtract = false;
		regs.f.half_carry = false;
		regs.f.carry = regs.a & 0x1;
		regs.a >>= 1;
		regs.f.zero = regs.a == 0;
	}

	void ldhlspr8() {
		i8 n = bus.read_signed_byte(pc + 1);
		regs.hl = sp + n;
		regs.f.zero = false;
		regs.f.subtract = false;
		regs.f.half_carry = (sp & 0xf) + (n & 0xf) > 0xf;
		regs.f.carry = (sp & 0xff) + (n & 0xff) > 0xff;
	}

	void push(u16 value) {
		bus.write_word(sp -= 2, value);
	}

	u16 pop() {
		return bus.read_word(sp);
		sp += 2;
	}

	void rra() {
		bool temp = regs.a;
		regs.a = regs.a >> 1 | regs.f.carry << 7;
		regs.f.carry = temp;
		regs.f.subtract = false;
		regs.f.half_carry = false;
	}

	void rla() {
		bool temp = regs.a >> 7;
		regs.a = regs.a << 1 | regs.f.carry;
		regs.f.carry = temp;
		regs.f.subtract = false;
		regs.f.half_carry = false;
	}

	void daa() {
		u8 a = regs.a;
		if(regs.f.subtract) {
			if(regs.f.half_carry)
				a = (a - 0x6) & 0xff;
			if(regs.f.carry)
				a -= 0x60;
		} else {
			if(regs.f.half_carry || (a & 0xf) > 0x9)
				a += 0x6;
			if(regs.f.carry || a > 0x9f)
				a += 0x60;
		}

		regs.a = a & 0xff;

		regs.f.zero = regs.a == 0;
		regs.f.half_carry = false;
		if((a & 0x100) == 0x100)
			regs.f.carry = true;
	}

	void scf() {
		regs.f.carry = true;
		regs.f.half_carry = false;
		regs.f.subtract = false;
	}

	void ccf() {
		regs.f.carry = ~regs.f.carry;
		regs.f.half_carry = false;
		regs.f.subtract = false;
	}

	void cpl() {
		regs.a = ~regs.a;
		regs.f.subtract = true;
		regs.f.half_carry = true;
	}

	void inc_byte(u8& value) {
		value++;
		regs.f.zero = !value;
		regs.f.subtract = false;
		regs.f.half_carry = !(value & 0xf);
	}
	
	void dec_byte(u8& value) {
		value--;
		regs.f.zero = !value;
		regs.f.subtract = true;
		regs.f.half_carry = !~(value & 0xf);
	}

	void call() {
		push(pc + 3);
		pc = bus.read_word(pc + 1);
	}
};



int main() {
	return 0;
}