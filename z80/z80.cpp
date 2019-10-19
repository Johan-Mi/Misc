#include <cstdint>
#include <cstddef>
#include <cassert>

using u8 = uint8_t;
using u16 = uint16_t;

class Z80 {
	virtual u8 readByte(u16 address) = 0;
	virtual void writeByte(u16 address, u8 value) = 0;
	
	u16 readWord(u16 address) {
		return readByte(address) | (readByte(address + 1) << 8);
	}

	void writeWord(u16 address, u16 value) {
		writeByte(address, value);
		writeByte(address + 1, value >> 8);
	}

	struct Flags {
		union {
			struct {
				bool S  : 1;
				bool Z  : 1;
				bool Y  : 1;
				bool H  : 1;
				bool X  : 1;
				bool P  : 1;
				bool N  : 1;
				bool C  : 1;
			};
			u8 raw;
		};
	};
	union {
		struct {
			Flags F;
			u8 A;
		};
		u16 AF;
	};
	union {
		struct {
			u8 C, B;
		};
		u16 BC;
	};
	union {
		struct {
			u8 E, D;
		};
		u16 DE;
	};
	union {
		struct {
			u8 L, H;
		};
		u16 HL;
	};
	union {
		struct {
			Flags Fp;
			u8 Ap;
		};
		u16 AFp;
	};
	union {
		struct {
			u8 Cp, Bp;
		};
		u16 BCp;
	};
	union {
		struct {
			u8 Ep, Dp;
		};
		u16 DEp;
	};
	union {
		struct {
			u8 Lp, Hp;
		};
		u16 HLp;
	};

	u16 PC;
	u16 SP;
	u16 IX;
	u16 IY;
	u8 I;
	u8 R;

	bool enableInterrupts;

	public:
	void reset() {
		enableInterrupts = false;
		PC = 0;
		I = 0;
		R = 0;
		AF = 0xffff;
		SP = 0xffff;
	}

	Z80() {
		reset();
	}

	void step()	{
		u8 currentInstruction = readByte(PC++);
		
		switch(currentInstruction) {
		case 0x00: // nop
			break;
		case 0x01: // ld BC,**
			BC = readWord(PC);
			PC += 2;
			break;
		case 0x02: //
			break;
		case 0x03: //
			break;
		case 0x04: //
			break;
		case 0x05: //
			break;
		case 0x06: //
			break;
		case 0x07: //
			break;
		case 0x08: //
			break;
		case 0x09: //
			break;
		case 0x0a: //
			break;
		case 0x0b: //
			break;
		case 0x0c: //
			break;
		case 0x0d: //
			break;
		case 0x0e: //
			break;
		case 0x0f: //
			break;
		case 0x10: //
			break;
		case 0x11: // ld DE,**
			DE = readWord(PC);
			PC += 2;
			break;
		case 0x12: //
			break;
		case 0x13: //
			break;
		case 0x14: //
			break;
		case 0x15: //
			break;
		case 0x16: //
			break;
		case 0x17: //
			break;
		case 0x18: //
			break;
		case 0x19: //
			break;
		case 0x1a: //
			break;
		case 0x1b: //
			break;
		case 0x1c: //
			break;
		case 0x1d: //
			break;
		case 0x1e: //
			break;
		case 0x1f: //
			break;
		case 0x20: //
			break;
		case 0x21: // ld HL,**
			HL = readWord(PC);
			PC += 2;
			break;
		case 0x22: //
			break;
		case 0x23: //
			break;
		case 0x24: //
			break;
		case 0x25: //
			break;
		case 0x26: //
			break;
		case 0x27: //
			break;
		case 0x28: //
			break;
		case 0x29: //
			break;
		case 0x2a: //
			break;
		case 0x2b: //
			break;
		case 0x2c: //
			break;
		case 0x2d: //
			break;
		case 0x2e: //
			break;
		case 0x2f: //
			break;
		case 0x30: //
			break;
		case 0x31: // ld SP,**
			SP = readWord(PC);
			PC += 2;
			break;
		case 0x32: //
			break;
		case 0x33: //
			break;
		case 0x34: //
			break;
		case 0x35: //
			break;
		case 0x36: //
			break;
		case 0x37: //
			break;
		case 0x38: //
			break;
		case 0x39: //
			break;
		case 0x3a: //
			break;
		case 0x3b: //
			break;
		case 0x3c: //
			break;
		case 0x3d: //
			break;
		case 0x3e: //
			break;
		case 0x3f: //
			break;

		case 0x40 ... 0x7f: // mov REG,REG
			u8 src;
			switch(currentInstruction & 0b00000111) {
			case 0x0:	src = B;			break;
			case 0x1:	src = C;			break;	
			case 0x2:	src = D;			break;
			case 0x3:	src = E;			break;
			case 0x4:	src = H;			break;
			case 0x5:	src = L;			break;
			case 0x6:	src = readByte(HL);	break;
			case 0x7:	src = A;			break;
			}
			switch(currentInstruction & 0b11111000) {
			case 0x40:	B = src;			break;
			case 0x48:	C = src;			break;
			case 0x50:	D = src;			break;
			case 0x58:	E = src;			break;
			case 0x60:	H = src;			break;
			case 0x68:	L = src;			break;
			case 0x70:	writeByte(HL, src);	break;
			case 0x78:	A = src;			break;
			}
			break;

		case 0x80: //
			break;
		case 0x81: //
			break;
		case 0x82: //
			break;
		case 0x83: //
			break;
		case 0x84: //
			break;
		case 0x85: //
			break;
		case 0x86: //
			break;
		case 0x87: //
			break;
		case 0x88: //
			break;
		case 0x89: //
			break;
		case 0x8a: //
			break;
		case 0x8b: //
			break;
		case 0x8c: //
			break;
		case 0x8d: //
			break;
		case 0x8e: //
			break;
		case 0x8f: //
			break;
		case 0x90: //
			break;
		case 0x91: //
			break;
		case 0x92: //
			break;
		case 0x93: //
			break;
		case 0x94: //
			break;
		case 0x95: //
			break;
		case 0x96: //
			break;
		case 0x97: //
			break;
		case 0x98: //
			break;
		case 0x99: //
			break;
		case 0x9a: //
			break;
		case 0x9b: //
			break;
		case 0x9c: //
			break;
		case 0x9d: //
			break;
		case 0x9e: //
			break;
		case 0x9f: //
			break;
		case 0xa0: //
			break;
		case 0xa1: //
			break;
		case 0xa2: //
			break;
		case 0xa3: //
			break;
		case 0xa4: //
			break;
		case 0xa5: //
			break;
		case 0xa6: //
			break;
		case 0xa7: //
			break;
		case 0xa8: //
			break;
		case 0xa9: //
			break;
		case 0xaa: //
			break;
		case 0xab: //
			break;
		case 0xac: //
			break;
		case 0xad: //
			break;
		case 0xae: //
			break;
		case 0xaf: //
			break;
		case 0xb0: //
			break;
		case 0xb1: //
			break;
		case 0xb2: //
			break;
		case 0xb3: //
			break;
		case 0xb4: //
			break;
		case 0xb5: //
			break;
		case 0xb6: //
			break;
		case 0xb7: //
			break;
		case 0xb8: //
			break;
		case 0xb9: //
			break;
		case 0xba: //
			break;
		case 0xbb: //
			break;
		case 0xbc: //
			break;
		case 0xbd: //
			break;
		case 0xbe: //
			break;
		case 0xbf: //
			break;
		case 0xc0: //
			break;
		case 0xc1: //
			break;
		case 0xc2: //
			break;
		case 0xc3: //
			break;
		case 0xc4: //
			break;
		case 0xc5: //
			break;
		case 0xc6: //
			break;
		case 0xc7: // rst 00h
			rst(0x00);
			break;
		case 0xc8: //
			break;
		case 0xc9: //
			break;
		case 0xca: //
			break;
		//CB prefix
		case 0xcc: //
			break;
		case 0xcd: //
			break;
		case 0xce: //
			break;
		case 0xcf: // rst 08h
			rst(0x08);
			break;
		case 0xd0: //
			break;
		case 0xd1: //
			break;
		case 0xd2: //
			break;
		case 0xd3: //
			break;
		case 0xd4: //
			break;
		case 0xd5: //
			break;
		case 0xd6: //
			break;
		case 0xd7: // rst 10h
			rst(0x10);
			break;
		case 0xd8: //
			break;
		case 0xd9: //
			break;
		case 0xda: //
			break;
		case 0xdb: //
			break;
		case 0xdc: //
			break;
		//DD prefix
		case 0xde: //
			break;
		case 0xdf: // rst 18h
			rst(0x18);
			break;
		case 0xe0: //
			break;
		case 0xe1: //
			break;
		case 0xe2: //
			break;
		case 0xe3: //
			break;
		case 0xe4: //
			break;
		case 0xe5: //
			break;
		case 0xe6: //
			break;
		case 0xe7: // rst 20h
			rst(0x20);
			break;
		case 0xe8: //
			break;
		case 0xe9: //
			break;
		case 0xea: //
			break;
		case 0xeb: //
			break;
		case 0xec: //
			break;
		//ED prefix
		case 0xee: //
			break;
		case 0xef: // rst 28h
			rst(0x28);
			break;
		case 0xf0: //
			break;
		case 0xf1: //
			break;
		case 0xf2: //
			break;
		case 0xf3: //
			break;
		case 0xf4: //
			break;
		case 0xf5: //
			break;
		case 0xf6: //
			break;
		case 0xf7: // rst 30h
			rst(0x30);
			break;
		case 0xf8: //
			break;
		case 0xf9: //
			break;
		case 0xfa: //
			break;
		case 0xfb: //
			break;
		case 0xfc: //
			break;
		//FD prefix
		case 0xfe: //
			break;
		case 0xff: // rst 38h
			rst(0x38);
			break;
			;

		case 0xed:
			//ED instructions
			break;
		case 0xcb:
			//CB instructions
			break;
		case 0xdd:
			//DD instructions
			switch(readByte(PC++)) {
			case 0xcb:
				//DDCB instructions
				break;
			default:
				assert(!"Unknown DD instruction in step()");
			}
			break;
		case 0xfd:
			//FD instructions
			switch(readByte(PC++)) {
			case 0xcb:
				//FDCB instructions
				break;
			default:
				assert(!"Unknown FDCB instruction in step()");
			}
			break;
		default:
			assert(!"Unknown instruction in step()");
		}
	}

	private:
	void push(u8 value) {
		writeByte(--PC, value);
	}

	void rst(u16 value) {
		push(PC);
		PC = value;
	}

};
