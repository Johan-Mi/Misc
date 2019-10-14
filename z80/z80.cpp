#include <cstdint>
#include <cstddef>
#include <cassert>

using u8 = uint8_t;
using u16 = uint16_t;

class Z80 {
	virtual u8 readByte(u16 address) = 0;
	virtual void writeByte(u16 address) = 0;
	
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
			}
			u8 raw;
		}
	}
	union {
		struct {
			Flags F;
			u8 A;
		}
		u16 AF;
	}
	union {
		struct {
			u8 C, B;
		}
		u16 BC;
	}
	union {
		struct {
			u8 E, D;
		}
		u16 DE;
	}
	union {
		struct {
			u8 L, H;
		}
		u16 HL;
	}
	union {
		struct {
			Flags Fp;
			u8 Ap;
		}
		u16 AFp;
	}
	union {
		struct {
			u8 Cp, Bp;
		}
		u16 BCp;
	}
	union {
		struct {
			u8 Ep, Dp;
		}
		u16 DEp;
	}
	union {
		struct {
			u8 Lp, Hp;
		}
		u16 HLp;
	}

	u16 PC;
	u16 SP;
	u16 IX;
	u16 IY;
	u8 I;
	u8 R;

	bool enableInterrupts;

	void reset() {
		enableInterrupts = false;
		PC = 0;
		I = 0;
		R = 0;
		AF = 0xffff;
		SP = 0xffff;
	}

	void step()	{
		u8 currentInstruction = readByte(pc++);
		
		switch(currentInstruction) {
		
		default:
			assert(!"Unknown opcode in step()");
		}
	}
}
