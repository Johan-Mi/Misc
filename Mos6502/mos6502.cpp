#include <stdint.h>

using u8 = uint8_t;
using u16 = uint16_t;
using i8 = int8_t;

class Mos6502 {
	u8 A;
	u8 X;
	u8 Y;

	union {
		struct {
			bool N : 1;
			bool V : 1;
			bool _ : 1;
			bool B : 1;
			bool D : 1;
			bool I : 1;
			bool Z : 1;
			bool C : 1;
		};
		u8 raw;
	} flags;

	u16 PC;
	u8 S;



	void movGeneric(const u8 src, u8& dest) {
		dest = src;
		flags.Z = !dest;
		flags.N = dest >> 7;
	}

	void ADC(const u8 value) {
		// TODO: Add support for decimal mode
		u16 sum = A + value + flags.C;
		flags.C = sum > 0xff;
		flags.V = ~(A ^ value) & (A ^ sum) & 0x80;
		A = sum;
		flags.Z = !A;
		flags.N = A >> 7;
	}
	void AND(const u8 value) {
		A &= value;
		flags.Z = !A;
		flags.N = A >> 7;
	}
	void ASL(u8& value) {
		flags.C = value >> 7;
		value >>= 1;
		flags.Z = !value;
		flags.N = value >> 7;
	}
	bool BCC(const i8 value) {
		if(!flags.C)
			PC += value;
		return !flags.C;
	}
	bool BCS(const i8 value) {
		if(flags.C)
			PC += value;
		return flags.C;
	}
	bool BEQ(const i8 value) {
		if(flags.Z)
			PC += value;
		return flags.Z;
	}
	void BIT(const u8 value) {
		u8 result = A & value;
		flags.Z = !result;
		flags.N = result >> 7;
		flags.V = result >> 6 & 1;
	}
	bool BMI(const i8 value) {
		if(flags.N)
			PC += value;
		return flags.N;
	}
	bool BNE(const i8 value) {
		if(!flags.Z)
			PC += value;
		return !flags.Z;
	}
	bool BPL(const i8 value) {
		if(!flags.N)
			PC += value;
		return !flags.N;
	}
	void BRK() {
		// TODO: Implement interrupts
	}
	bool BVC(const i8 value) {
		if(!flags.V)
			PC += value;
		return !flags.V;
	}
	bool BVS(const i8 value) {
		if(flags.V)
			PC += value;
		return flags.V;
	}
	void CLC() { flags.C = 0; }
	void CLD() { flags.D = 0; }
	void CLI() { flags.I = 0; }
	void CLV() { flags.V = 0; }
	void CMP(const u8 value) {
		flags.Z = A == value;
		flags.N = (A - value) >> 7;
		flags.C = value > A;
	}
	void CPX(const u8 value) {
		flags.Z = X == value;
		flags.N = (X - value) >> 7;
		flags.C = value > X;
	}
	void CPY(const u8 value) {
		flags.Z = Y == value;
		flags.N = (Y - value) >> 7;
		flags.C = value > Y;
	}
	void DEC(u8& value) {
		value--;
		flags.Z = !value;
		flags.N = value >> 7;
	}
	void DEX() { DEC(X); }
	void DEY() { DEC(Y); }
	void EOR(const u8 value) {
		A ^= value;
		flags.Z = !A;
		flags.N = A >> 7;
	}
	void INC(u8& value) {
		value++;
		flags.Z = !value;
		flags.N = value >> 7;
	}
	void INX() { INC(X); }
	void INY() { INC(Y); }
	void JMP(const u8 value) { PC = value; }
	void JSR(const u8 value) {
		pushWord(PC + 1);
		PC = value;
	}
	void LDA(const u8 value) { movGeneric(value, A); }
	void LDX(const u8 value) { movGeneric(value, X); }
	void LDY(const u8 value) { movGeneric(value, Y); }
	void LSR(u8& value) {
		flags.C = value;
		value >>= 1;
		flags.N = 0;
		flags.Z = !value;
	}
	void NOP() { /* Does nothing */ }
	void ORA(const u8 value) {
		A |= value;
		flags.Z = !A;
		flags.N = A >> 7;
	}
	void PHA() { pushByte(A); }
	void PHP() { pushByte(flags.raw); }
	void PLA() { A = popByte(); }
	void PLP() { flags.raw = popByte(); }
	void ROL(u8& value) {
		bool temp = flags.C;
		flags.C = value >> 7;
		value = value << 1 | temp;
		flags.N = value >> 7;
		flags.Z = !value;
	}
	void ROR(u8& value) {
		bool temp = flags.C;
		flags.C = value;
		value = value >> 1 | temp << 7;
		flags.N = value >> 7;
		flags.Z = !value;
	}
	void RTI() {
		flags.raw = popByte();
		PC = popWord();
	}
	void RTS() { PC = popWord() + 1; }
	void SBC(const u8 value) { ADC(~value); }
	void SEC() { flags.C = 1; }
	void SED() { flags.D = 1; }
	void SEI() { flags.I = 1; }
	void STA(const u16 address) { writeByte(address, A); }
	void STX(const u16 address) { writeByte(address, X); }
	void STY(const u16 address) { writeByte(address, Y); }
	void TAX() { movGeneric(A, X); }
	void TAY() { movGeneric(A, Y); }
	void TSX() { movGeneric(S, X); }
	void TXA() { movGeneric(X, A); }
	void TXS() { movGeneric(X, S); }
	void TYA() { movGeneric(Y, A); }



public:
	void reset() {
		flags.B = 1;
		flags.D = 0;
		flags.I = 1;
		flags._ = 1;
		PC = readWord(0xfffc);
		S = 0xff;
	}

	virtual u8 readByte(u16 addresss);
	virtual void writeByte(u16 address, u8 value);

	u16 readWord(u16 address) {
		return (u16)readByte(address + 1) << 8 | readByte(address);
	}
	u16 writeWord(u16 address, u16 value) {
		writeByte(address, value);
		writeByte(address + 1, value >> 8);
	}

	u8 popByte() {
		return readByte(++S);
	}
	void pushByte(u8 value) {
		writeByte(S--, value);
	}

	u16 popWord() {
		return popByte() | (u16)popByte() >> 8;
	}
	void pushWord(u16 value) {
		pushByte(value >> 8);
		pushByte(value);
	}

	void step() {
		switch(readByte(PC++)) {
		case 0x00: // BRK
			BRK();
			break;
		case 0x01:
		case 0x02:
		case 0x03:
		case 0x04:
		case 0x05:
		case 0x06:
		case 0x07:
		case 0x08: // PHP
			PHP();
			break;
		case 0x09:
		case 0x0a:
		case 0x0b:
		case 0x0c:
		case 0x0d:
		case 0x0e:
		case 0x0f: // Invalid
			break;
		case 0x10:
		case 0x11:
		case 0x12:
		case 0x13:
		case 0x14:
		case 0x15:
		case 0x16:
		case 0x17:
		case 0x18: // CLC
			CLC();
			break;
		case 0x19:
		case 0x1a:
		case 0x1b:
		case 0x1c:
		case 0x1d:
		case 0x1e:
		case 0x1f: // Invalid
			break;
		case 0x20:
		case 0x21:
		case 0x22:
		case 0x23:
		case 0x24:
		case 0x25:
		case 0x26:
		case 0x27:
		case 0x28: // PLP
			PLP();
			break;
		case 0x29:
		case 0x2a:
		case 0x2b:
		case 0x2c:
		case 0x2d:
		case 0x2e:
		case 0x2f: // Invalid
			break;
		case 0x30:
		case 0x31:
		case 0x32:
		case 0x33:
		case 0x34:
		case 0x35:
		case 0x36:
		case 0x37:
		case 0x38: // SEC
			SEC();
			break;
		case 0x39:
		case 0x3a:
		case 0x3b:
		case 0x3c:
		case 0x3d:
		case 0x3e:
		case 0x3f: // Invalid
			break;
		case 0x40: // RTI
			RTI();
			break;
		case 0x41:
		case 0x42:
		case 0x43:
		case 0x44:
		case 0x45:
		case 0x46:
		case 0x47:
		case 0x48: // PHA
			PHA();
			break;
		case 0x49:
		case 0x4a:
		case 0x4b:
		case 0x4c:
		case 0x4d:
		case 0x4e:
		case 0x4f: // Invalid
			break;
		case 0x50:
		case 0x51:
		case 0x52:
		case 0x53:
		case 0x54:
		case 0x55:
		case 0x56:
		case 0x57:
		case 0x58: // CLI
			CLI();
			break;
		case 0x59:
		case 0x5a:
		case 0x5b:
		case 0x5c:
		case 0x5d:
		case 0x5e:
		case 0x5f: // Invalid
			break;
		case 0x60: // RTS
			RTS();
			break;
		case 0x61:
		case 0x62:
		case 0x63:
		case 0x64:
		case 0x65:
		case 0x66:
		case 0x67:
		case 0x68: // PLA
			PLA();
			break;
		case 0x69:
		case 0x6a:
		case 0x6b:
		case 0x6c:
		case 0x6d:
		case 0x6e:
		case 0x6f: // Invalid
			break;
		case 0x70:
		case 0x71:
		case 0x72:
		case 0x73:
		case 0x74:
		case 0x75:
		case 0x76:
		case 0x77:
		case 0x78: // SEI
			SEI();
			break;
		case 0x79:
		case 0x7a:
		case 0x7b:
		case 0x7c:
		case 0x7d:
		case 0x7e:
		case 0x7f: // Invalid
			break;
		case 0x80:
		case 0x81:
		case 0x82:
		case 0x83:
		case 0x84:
		case 0x85:
		case 0x86:
		case 0x87:
		case 0x88: // DEY
			DEY();
			break;
		case 0x89:
		case 0x8a: // TXA
			TXA();
			break;
		case 0x8b:
		case 0x8c:
		case 0x8d:
		case 0x8e:
		case 0x8f: // Invalid
			break;
		case 0x90:
		case 0x91:
		case 0x92:
		case 0x93:
		case 0x94:
		case 0x95:
		case 0x96:
		case 0x97:
		case 0x98: // TYA
			TYA();
			break;
		case 0x99:
		case 0x9a: // TXS
			TXS();
			break;
		case 0x9b:
		case 0x9c:
		case 0x9d:
		case 0x9e:
		case 0x9f: // Invalid
			break;
		case 0xa0:
		case 0xa1:
		case 0xa2:
		case 0xa3:
		case 0xa4:
		case 0xa5:
		case 0xa6:
		case 0xa7:
		case 0xa8: // TAY
			TAY();
			break;
		case 0xa9:
		case 0xaa: // TAX
			TAX();
			break;
		case 0xab:
		case 0xac:
		case 0xad:
		case 0xae:
		case 0xaf: // Invalid
			break;
		case 0xb0:
		case 0xb1:
		case 0xb2:
		case 0xb3:
		case 0xb4:
		case 0xb5:
		case 0xb6:
		case 0xb7:
		case 0xb8: // CLV
			CLV();
			break;
		case 0xb9:
		case 0xba: // TSX
			TSX();
			break;
		case 0xbb:
		case 0xbc:
		case 0xbd:
		case 0xbe:
		case 0xbf: // Invalid
			break;
		case 0xc0:
		case 0xc1:
		case 0xc2:
		case 0xc3:
		case 0xc4:
		case 0xc5:
		case 0xc6:
		case 0xc7:
		case 0xc8: // INY
			INY();
			break;
		case 0xc9:
		case 0xca: // DEX
			DEX();
			break;
		case 0xcb:
		case 0xcc:
		case 0xcd:
		case 0xce:
		case 0xcf: // Invalid
			break;
		case 0xd0:
		case 0xd1:
		case 0xd2:
		case 0xd3:
		case 0xd4:
		case 0xd5:
		case 0xd6:
		case 0xd7:
		case 0xd8: // CLD
			CLD();
			break;
		case 0xd9:
		case 0xda:
		case 0xdb:
		case 0xdc:
		case 0xdd:
		case 0xde:
		case 0xdf: // Invalid
			break;
		case 0xe0:
		case 0xe1:
		case 0xe2:
		case 0xe3:
		case 0xe4:
		case 0xe5:
		case 0xe6:
		case 0xe7:
		case 0xe8: // INX
			INX();
			break;
		case 0xe9:
		case 0xea: // NOP
			NOP();
			break;
		case 0xeb:
		case 0xec:
		case 0xed:
		case 0xee:
		case 0xef: // Invalid
			break;
		case 0xf0:
		case 0xf1:
		case 0xf2:
		case 0xf3:
		case 0xf4:
		case 0xf5:
		case 0xf6:
		case 0xf7:
		case 0xf8: // SED
			SED();
			break;
		case 0xf9:
		case 0xfa:
		case 0xfb:
		case 0xfc:
		case 0xfd:
		case 0xfe:
		case 0xff: // Invalid
			break;
		}
	}

	Mos6502() {
		reset();
	}
	
};
