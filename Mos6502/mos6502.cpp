#include <stdint.h>
#include <cassert>

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

	struct MemLocation {
		u16 address;
		MemLocation(u16 a) : address(a) {}
		operator u16&() { return address; }
	};

	u8 read(u8 location) { return location; }
	u8 read(MemLocation location) { return readByte(location); }
	void write(u8& location, u8 value) { location = value; }
	void write(MemLocation location, u8 value) { writeByte(location, value); }

	void movGeneric(auto src, auto dest) {
		u8 temp = read(src);
		flags.Z = !temp;
		flags.N = temp >> 7;
		write(dest, temp);
	}
	bool conditionalBranch(bool condition, i8 value) {
		if(condition)
			PC += value;
		return condition;
	}

	void ADC(auto location) {
		// TODO: Add support for decimal mode
		u8 temp = read(location);
		u16 sum = A + temp + flags.C;
		flags.C = sum > 0xff;
		flags.V = ~(A ^ temp) & (A ^ sum) & 0x80;
		A = sum;
		flags.Z = !A;
		flags.N = A >> 7;
	}
	void AND(auto location) {
		A &= read(location);
		flags.Z = !A;
		flags.N = A >> 7;
	}
	void ASL(auto location) {
		u8 temp = read(location);
		flags.C = temp >> 7;
		flags.Z = !temp;
		flags.N = temp >> 7;
		write(location, temp << 1);
	}
	bool BCC(const i8 value) { return conditionalBranch(!flags.C, value); }
	bool BCS(const i8 value) { return conditionalBranch( flags.C, value); }
	bool BEQ(const i8 value) { return conditionalBranch( flags.Z, value); }
	void BIT(auto location) {
		u8 result = A & read(location);
		flags.Z = !result;
		flags.N = result >> 7;
		flags.V = result >> 6 & 1;
	}
	bool BMI(const i8 value) { return conditionalBranch( flags.N, value); }
	bool BNE(const i8 value) { return conditionalBranch(!flags.Z, value); }
	bool BPL(const i8 value) { return conditionalBranch(!flags.N, value); }
	void BRK() {
		bool oldB = flags.B;
		flags.B = true;
		sendIrq();
		flags.B = oldB;
	}
	bool BVC(const i8 value) { return conditionalBranch(!flags.V, value); }
	bool BVS(const i8 value) { return conditionalBranch( flags.V, value); }
	void CLC() { flags.C = 0; }
	void CLD() { flags.D = 0; }
	void CLI() { flags.I = 0; }
	void CLV() { flags.V = 0; }
	void CMP(auto location) {
		u8 temp = read(location);
		flags.Z = A == temp;
		flags.N = (A - temp) >> 7;
		flags.C = temp > A;
	}
	void CPX(auto location) {
		u8 temp = read(location);
		flags.Z = X == temp;
		flags.N = (X - temp) >> 7;
		flags.C = temp > X;
	}
	void CPY(auto location) {
		u8 temp = read(location);
		flags.Z = Y == temp;
		flags.N = (Y - temp) >> 7;
		flags.C = temp > Y;
	}
	void DEC(auto location) {
		u8 temp = read(location) - 1;
		flags.Z = !temp;
		flags.N = temp >> 7;
		write(location, temp);
	}
	void DEX() { DEC(X); }
	void DEY() { DEC(Y); }
	void EOR(auto location) {
		A ^= read(location);
		flags.Z = !A;
		flags.N = A >> 7;
	}
	void INC(auto location) {
		u8 temp = read(location) + 1;
		flags.Z = !temp;
		flags.N = temp >> 7;
		write(location, temp);
	}
	void INX() { INC(X); }
	void INY() { INC(Y); }
	void JMP(const u16 value) { PC = value; }
	void JSR(const u16 value) {
		pushWord(PC + 1);
		PC = value;
	}
	void LDA(auto location) { movGeneric(location, A); }
	void LDX(auto location) { movGeneric(location, X); }
	void LDY(auto location) { movGeneric(location, Y); }
	void LSR(auto location) {
		u8 temp = read(location);
		flags.C = temp;
		flags.N = 0;
		flags.Z = !temp;
		write(location, temp >> 1);
	}
	void NOP() { /* Does nothing */ }
	void ORA(auto location) {
		A |= read(location);
		flags.Z = !A;
		flags.N = A >> 7;
	}
	void PHA() { pushByte(A); }
	void PHP() { pushByte(flags.raw); }
	void PLA() { A = popByte(); }
	void PLP() { flags.raw = popByte(); }
	void ROL(auto location) {
		u8 temp = read(location);
		bool oldCarry = flags.C;
		flags.C = temp >> 7;
		flags.N = temp >> 7;
		flags.Z = !(temp & 0x7f);
		write(location, temp << 1 | oldCarry);
	}
	void ROR(auto location) {
		u8 temp = read(location);
		bool oldCarry = flags.C;
		flags.C = temp;
		temp = temp >> 1 | oldCarry << 7;
		flags.N = temp >> 7;
		flags.Z = !temp;
		write(location, temp);
	}
	void RTI() {
		flags.raw = popByte();
		PC = popWord();
	}
	void RTS() { PC = popWord() + 1; }
	void SBC(auto location) { ADC(~read(location)); }
	void SEC() { flags.C = 1; }
	void SED() { flags.D = 1; }
	void SEI() { flags.I = 1; }
	void STA(auto location) { write(location, A); }
	void STX(auto location) { write(location, X); }
	void STY(auto location) { write(location, Y); }
	void TAX() { movGeneric(A, X); }
	void TAY() { movGeneric(A, Y); }
	void TSX() { movGeneric(S, X); }
	void TXA() { movGeneric(X, A); }
	void TXS() { movGeneric(X, S); }
	void TYA() { movGeneric(Y, A); }

	void invalidOpcode() { assert(!"Invalid opcode"); }



public:
	void sendReset() {
		flags.B = 1;
		flags.D = 0;
		flags.I = 1;
		flags._ = 1;
		PC = readWord(0xfffc);
		S = 0xff;
	}
	void sendNmi() {

	}
	void sendIrq() {

	}

	virtual u8 readByte(u16 addresss);
	virtual void writeByte(u16 address, u8 value);

	u16 readWord(u16 address) { return (u16)readByte(address + 1) << 8 | readByte(address); }
	u16 writeWord(u16 address, u16 value) {
		writeByte(address, value);
		writeByte(address + 1, value >> 8);
	}

	u8 popByte() { return readByte(++S); }
	void pushByte(u8 value) { writeByte(S--, value); }
	u16 popWord() { return popByte() | (u16)popByte() >> 8; }
	void pushWord(u16 value) {
		pushByte(value >> 8);
		pushByte(value);
	}

	MemLocation operandImm()	{ return PC + 1; }
	MemLocation operandZpg()	{ return readByte(PC + 1); }
	MemLocation operandAbs()	{ return readWord(PC + 1); }
	MemLocation operandAbsX()	{ return readWord(PC + 1) + X; }
	MemLocation operandAbsY()	{ return readWord(PC + 1) + Y; }
	MemLocation operandXInd()	{ return readWord((readByte(PC + 1) + X) & 0xff); }
	MemLocation operandIndY()	{ return readWord(readByte(PC + 1)) + Y; }
	MemLocation operandInd()	{ return readWord(readWord(PC + 1)); }
	MemLocation operandZpgX()	{ return (readByte(PC + 1) + X) & 0xff; }
	MemLocation operandZpgY()	{ return (readByte(PC + 1) + Y) & 0xff; }

	void step() {
		switch(readByte(PC)) {
		case 0x00: // BRK
			//BRK();
			// TODO: Implement interrupts
			assert(!"BRK hasn't been implemented yet");
			break;
		case 0x01: // ORA X,ind
			ORA(operandXInd());
			PC += 3;
			break;
		case 0x05: // ORA zpg
			ORA(operandZpg());
			PC += 2;
			break;
		case 0x06: // ASL zpg
			ASL(operandZpg());
			PC += 2;
			break;
		case 0x08: // PHP
			PHP();
			PC++;
			break;
		case 0x09: // ORA #
			ORA(operandImm());
			PC += 2;
			break;
		case 0x0a: // ASL A
			ASL(A);
			PC++;
			break;
		case 0x0d: // ORA abs
			ORA(operandAbs());
			PC += 3;
			break;
		case 0x0e: // ASL abs
			ASL(operandAbs());
			PC += 3;
			break;
		case 0x10: // BPL rel
			BPL(readByte(PC + 1));
			PC += 2;
			break;
		case 0x11: // ORA ind,y
			ORA(operandIndY());
			PC += 2;
			break;
		case 0x15: // ORA zpg,X
			ORA(operandZpgX());
			PC += 2;
			break;
		case 0x16: // ASL zpg,X
			ASL(operandZpgX());
			PC += 2;
			break;
		case 0x18: // CLC
			CLC();
			PC++;
			break;
		case 0x19: // ORA abs,Y
			ORA(operandAbsY());
			PC += 3;
			break;
		case 0x1d: // ORA abs,X
			ORA(operandAbsX());
			PC += 3;
			break;
		case 0x1e: // ASL abs,X
			ASL(operandAbsX());
			PC += 3;
			break;
		case 0x20: // JSR abs
			JSR(operandAbs());
			break;
		case 0x21: // AND X,ind
			AND(operandXInd());
			PC += 2;
			break;
		case 0x24: // BIT zpg
			BIT(operandZpg());
			PC += 2;
			break;
		case 0x25: // AND zpg
			AND(operandZpg());
			PC += 2;
			break;
		case 0x26: // ROL zpg
			ROL(operandZpg());
			PC += 2;
			break;
		case 0x28: // PLP
			PLP();
			PC++;
			break;
		case 0x29: // AND #
			AND(operandImm());
			PC += 2;
			break;
		case 0x2a: // ROL A
			ROL(A);
			PC++;
			break;
		case 0x2c: // BIT abs
			BIT(operandAbs());
			PC += 3;
			break;
		case 0x2d: // AND abs
			AND(operandAbs());
			PC += 3;
			break;
		case 0x2e: // ROL abs
			ROL(operandAbs());
			PC += 3;
			break;
		case 0x30: // BMI rel
			BMI(readByte(PC + 1));
			PC += 2;
			break;
		case 0x31: // AND ind,Y
			AND(operandIndY());
			PC += 2;
			break;
		case 0x35: // AND zpg,X
			AND(operandZpgX());
			PC += 2;
			break;
		case 0x36: // ROL zpg,X
			ROL(operandZpgX());
			PC += 2;
			break;
		case 0x38: // SEC
			SEC();
			PC++;
			break;
		case 0x39: // AND abs,Y
			AND(operandAbsY());
			PC += 3;
			break;
		case 0x3d: // AND abs,X
			AND(operandAbsX());
			PC += 3;
			break;
		case 0x3e: // LSR abs
			LSR(operandAbs());
			PC += 3;
			break;
		case 0x40: // RTI
			RTI();
			PC++;
			break;
		case 0x41: // EOR X,ind
			EOR(operandXInd());
			PC += 2;
			break;
		case 0x45: // EOR zpg
			EOR(operandZpg());
			PC += 2;
			break;
		case 0x46: // LSR zpg
			LSR(operandZpg());
			PC += 2;
			break;
		case 0x48: // PHA
			PHA();
			PC++;
			break;
		case 0x49: // EOR #
			EOR(operandImm());
			PC += 2;
			break;
		case 0x4a: // LSR A
			LSR(A);
			PC++;
			break;
		case 0x4c: // JMP abs
			JMP(operandAbs());
			PC += 3;
			break;
		case 0x4d: // EOR abs
			EOR(operandAbs());
			PC += 3;
			break;
		case 0x4e: // LSR abs
			LSR(operandAbs());
			PC += 3;
			break;
		case 0x50: // BVC rel
			BVC(readByte(PC + 1));
			PC += 2;
			break;
		case 0x51: // EOR ind,Y
			EOR(operandIndY());
			PC += 2;
			break;
		case 0x55: // EOR zpg,X
			EOR(operandZpgX());
			PC += 2;
			break;
		case 0x56: // LSR zpg,X
			LSR(operandZpgX());
			PC += 2;
			break;
		case 0x58: // CLI
			CLI();
			PC++;
			break;
		case 0x59: // EOR abs,Y
			EOR(operandAbsY());
			PC += 3;
			break;
		case 0x5d: // EOR abs,X
			EOR(operandAbsX());
			PC += 3;
			break;
		case 0x5e: // LSR abs,X
			LSR(operandAbsX());
			PC += 3;
			break;
		case 0x60: // RTS
			RTS();
			PC++;
			break;
		case 0x61: // ADC X,ind
			ADC(operandXInd());
			PC += 2;
			break;
		case 0x65: // ADC zpg
			ADC(operandZpg());
			PC += 2;
			break;
		case 0x66: // ROR zpg
			ROR(operandZpg());
			PC += 2;
			break;
		case 0x68: // PLA
			PLA();
			PC++;
			break;
		case 0x69: // ADC #
			ADC(operandImm());
			PC += 2;
			break;
		case 0x6a: // ROR A
			ROR(A);
			PC++;
			break;
		case 0x6c: // JMP ind
			JMP(operandInd());
			PC += 3;
			break;
		case 0x6d: // ADC abs
			ADC(operandAbs());
			PC += 3;
			break;
		case 0x6e: // ROR abs
			ROR(operandAbs());
			PC += 3;
			break;
		case 0x70: // BVS rel
			BVS(readByte(PC + 1));
			PC += 2;
			break;
		case 0x71: // ADC ind,Y
			ADC(operandIndY());
			PC += 2;
			break;
		case 0x75: // ADC zpg,X
			ADC(operandZpgX());
			PC += 2;
			break;
		case 0x76: // ROR zpg,X
			ROR(operandZpgX());
			PC += 2;
			break;
		case 0x78: // SEI
			SEI();
			PC++;
			break;
		case 0x79: // ADC abs,Y
			ADC(operandAbsY());
			PC += 3;
			break;
		case 0x7d: // ADC abs,X
			ADC(operandAbsX());
			PC += 3;
			break;
		case 0x7e: // ROR abs,X
			ROR(operandAbsX());
			PC += 3;
			break;
		case 0x81: // STA X,ind
			STA(operandXInd());
			PC += 2;
			break;
		case 0x84: // STY zpg
			STY(operandZpg());
			PC += 2;
			break;
		case 0x85: // STA zpg
			STA(operandZpg());
			PC += 2;
			break;
		case 0x86: // STX zpg
			STX(operandZpg());
			PC += 2;
			break;
		case 0x88: // DEY
			DEY();
			PC++;
			break;
		case 0x8a: // TXA
			TXA();
			PC++;
			break;
		case 0x8c: // STY abs
			STY(operandAbs());
			PC += 3;
			break;
		case 0x8d: // STA abs
			STA(operandAbs());
			PC += 3;
			break;
		case 0x8e: // STX abs
			STX(operandAbs());
			PC += 3;
			break;
		case 0x90: // BCC rel
			BCC(readByte(PC + 1));
			PC += 2;
			break;
		case 0x91: // STA ind,Y
			STA(operandIndY());
			PC += 2;
			break;
		case 0x94: // STY zpg,X
			STY(operandZpgX());
			PC += 2;
			break;
		case 0x95: // STA zpg,X
			STA(operandZpgX());
			PC += 2;
			break;
		case 0x96: // STA zpg,Y
			STA(operandZpgY());
			PC += 2;
			break;
		case 0x98: // TYA
			TYA();
			PC++;
			break;
		case 0x99: // STA abs,Y
			STA(operandAbsY());
			PC += 3;
			break;
		case 0x9a: // TXS
			TXS();
			PC++;
			break;
		case 0x9d: // STA abs,X
			STA(operandAbsX());
			PC += 3;
			break;
		case 0xa0: // LDY #
			LDY(operandImm());
			PC += 2;
			break;
		case 0xa1: // LDA X,ind
			LDA(operandXInd());
			PC += 2;
			break;
		case 0xa2: // LDX #
			LDX(operandImm());
			PC += 2;
			break;
		case 0xa4: // LDY zpg
			LDY(operandZpg());
			PC += 2;
			break;
		case 0xa5: // LDA zpg
			LDA(operandZpg());
			PC += 2;
			break;
		case 0xa6: // LDX zpg
			LDX(operandZpg());
			PC += 2;
			break;
		case 0xa8: // TAY
			TAY();
			PC++;
			break;
		case 0xa9: // LDA #
			LDA(operandImm());
			PC += 2;
			break;
		case 0xaa: // TAX
			TAX();
			PC++;
			break;
		case 0xac: // LDY abs
			LDY(operandAbs());
			PC += 3;
			break;
		case 0xad: // LDA abs
			LDA(operandAbs());
			PC += 3;
			break;
		case 0xae: // LDX abs
			LDX(operandAbs());
			PC += 3;
			break;
		case 0xb0: // BCS rel
			BCS(readByte(PC + 1));
			PC += 2;
			break;
		case 0xb1: // LDA ind,Y
			LDA(operandIndY());
			PC += 2;
			break;
		case 0xb4: // LDY zpg,X
			LDY(operandZpgX());
			PC += 2;
			break;
		case 0xb5: // LDA zpg,X
			LDA(operandZpgX());
			PC += 2;
			break;
		case 0xb6: // LDX zpg,Y
			LDX(operandZpgY());
			PC += 2;
			break;
		case 0xb8: // CLV
			CLV();
			PC++;
			break;
		case 0xb9: // LDA abs,Y
			LDA(operandAbsY());
			PC += 3;
			break;
		case 0xba: // TSX
			TSX();
			PC++;
			break;
		case 0xbc: // LDY abs,X
			LDY(operandAbsX());
			PC += 3;
			break;
		case 0xbd: // LDA abs,X
			LDA(operandAbsX());
			PC += 3;
			break;
		case 0xbe: // LDX abs,Y
			LDX(operandAbsY());
			PC += 3;
			break;
		case 0xc0: // CPY #
			CPY(operandImm());
			PC += 2;
			break;
		case 0xc1: // CMP X,ind
			CMP(operandXInd());
			PC += 2;
			break;
		case 0xc4: // CPY zpg
			CPY(operandZpg());
			PC += 2;
			break;
		case 0xc5: // CMP zpg
			CMP(operandZpg());
			PC += 2;
			break;
		case 0xc6: // DEC zpg
			DEC(operandZpg());
			PC += 2;
			break;
		case 0xc8: // INY
			INY();
			PC++;
			break;
		case 0xc9: // CMP #
			CMP(operandImm());
			PC += 2;
			break;
		case 0xca: // DEX
			DEX();
			PC++;
			break;
		case 0xcc: // CPY abs
			CPY(operandAbs());
			PC += 3;
			break;
		case 0xcd: // CMP abs
			CMP(operandAbs());
			PC += 3;
			break;
		case 0xce: // DEC abs
			DEC(operandAbs());
			PC += 3;
			break;
		case 0xd0: // BNE rel
			BNE(readByte(PC + 1));
			PC += 2;
			break;
		case 0xd1: // CMP ind,Y
			CMP(operandIndY());
			PC += 2;
			break;
		case 0xd5: // CMP zpg,X
			CMP(operandZpgX());
			PC += 2;
			break;
		case 0xd6: // DEC zpg,X
			DEC(operandZpgX());
			PC += 2;
			break;
		case 0xd8: // CLD
			CLD();
			PC++;
			break;
		case 0xd9: // CMP abs,Y
			CMP(operandAbsY());
			PC += 3;
			break;
		case 0xdd: // CMP abs,X
			CMP(operandAbsX());
			PC += 3;
			break;
		case 0xde: // DEC abs,X
			DEC(operandAbsX());
			PC += 3;
			break;
		case 0xe0: // CPX #
			CPX(operandImm());
			PC += 2;
			break;
		case 0xe1: // SBC X,ind
			SBC(operandXInd());
			PC += 2;
			break;
		case 0xe4: // CPX zpg
			CPX(operandZpg());
			PC += 2;
			break;
		case 0xe5: // SBC zpg
			SBC(operandZpg());
			PC += 2;
			break;
		case 0xe6: // INC zpg
			INC(operandZpg());
			PC += 2;
			break;
		case 0xe8: // INX
			INX();
			PC++;
			break;
		case 0xe9: // SBC #
			SBC(operandImm());
			PC += 2;
			break;
		case 0xea: // NOP
			NOP();
			PC++;
			break;
		case 0xec: // CPX abs
			CPX(operandAbs());
			PC += 3;
			break;
		case 0xed: // SBC abs
			SBC(operandAbs());
			PC += 3;
			break;
		case 0xee: // INC abs
			INC(operandAbs());
			PC += 3;
			break;
		case 0xf0: // BEQ rel
			BEQ(readByte(PC + 1));
			PC += 2;
			break;
		case 0xf1: // SBC ind,Y
			SBC(operandIndY());
			PC += 2;
			break;
		case 0xf5: // SBC zpg,X
			SBC(operandZpgX());
			PC += 2;
			break;
		case 0xf6: // INC zpg,X
			INC(operandZpgX());
			PC += 2;
			break;
		case 0xf8: // SED
			SED();
			PC++;
			break;
		case 0xf9: // SBC abs,Y
			SBC(operandAbsY());
			PC += 3;
			break;
		case 0xfd: // SBC abs,X
			SBC(operandAbsX());
			PC += 3;
			break;
		case 0xfe: // INC abs,X
			INC(operandAbsX());
			PC += 3;
			break;

		default: // Invalid
			invalidOpcode();
			break;
		}
	}

	Mos6502() {
		sendReset();
	}
	
};
