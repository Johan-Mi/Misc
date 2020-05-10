#pragma once

#include <stdint.h>

class Mos6502 {
	union [[nodiscard]] Flags {
		struct {
			bool N : 1; // Negative/sign
			bool V : 1; // Overflow
			bool _ : 1; // Unused
			bool B : 1; // ?
			bool D : 1; // Decimal
			bool I : 1; // Interrupt disable
			bool Z : 1; // Zero
			bool C : 1; // Carry
		};
		uint8_t raw;
	};

	struct [[nodiscard]] MemLocation {
		uint16_t address = 0;
		MemLocation(uint16_t const a);
		[[nodiscard]] constexpr operator uint16_t const&() const noexcept;
	};

	uint8_t A;
	uint8_t X;
	uint8_t Y;
	Flags flags;
	uint16_t PC;
	uint8_t S;

	constexpr uint8_t read(uint8_t const location) const noexcept;
	uint8_t read(MemLocation const location) const noexcept;
	void write(uint8_t &location, uint8_t const value) noexcept;
	void write(MemLocation location, uint8_t const value) noexcept;

	void movGeneric(auto const src, auto dest) noexcept;

	bool BCC(int8_t const value) noexcept;
	bool BCS(int8_t const value) noexcept;
	bool BEQ(int8_t const value) noexcept;
	bool BMI(int8_t const value) noexcept;
	bool BNE(int8_t const value) noexcept;
	bool BPL(int8_t const value) noexcept;
	bool BVC(int8_t const value) noexcept;
	bool BVS(int8_t const value) noexcept;

	void CLC() noexcept;
	void CLD() noexcept;
	void CLI() noexcept;
	void CLV() noexcept;

	void SEC() noexcept;
	void SED() noexcept;
	void SEI() noexcept;

	void CMP(auto const location) noexcept;
	void CPX(auto const location) noexcept;
	void CPY(auto const location) noexcept;

	void LDA(auto const location) noexcept;
	void LDX(auto const location) noexcept;
	void LDY(auto const location) noexcept;

	void STA(auto location) noexcept;
	void STX(auto location) noexcept;
	void STY(auto location) noexcept;

	void TAX() noexcept;
	void TAY() noexcept;
	void TSX() noexcept;
	void TXA() noexcept;
	void TXS() noexcept;
	void TYA() noexcept;

	void ADC(auto const location) noexcept;
	void AND(auto const location) noexcept;
	void ASL(auto const location) noexcept;
	void BIT(auto const location) noexcept;
	void BRK() noexcept;
	void DEC(auto location) noexcept;
	void DEX();
	void DEY();
	void EOR(auto const location) noexcept;
	void INC(auto location) noexcept;
	void INX();
	void INY();
	void JMP(uint16_t const value) noexcept;
	void JSR(uint16_t const value) noexcept;
	void LSR(auto location) noexcept;
	void ORA(auto const location) noexcept;
	void PHA() noexcept;
	void PHP() noexcept;
	void PLA() noexcept;
	void PLP() noexcept;
	void ROL(auto location) noexcept;
	void ROR(auto location) noexcept;
	void RTI() noexcept;
	void RTS() noexcept;
	void SBC(auto const location) noexcept;

	[[nodiscard]] MemLocation opImm() const noexcept;
	MemLocation opZpg() const noexcept;
	MemLocation opAbs() const noexcept;
	MemLocation opAbsX() const noexcept;
	MemLocation opAbsY() const noexcept;
	MemLocation opXInd() const noexcept;
	MemLocation opIndY() const noexcept;
	MemLocation opInd() const noexcept;
	MemLocation opZpgX() const noexcept;
	MemLocation opZpgY() const noexcept;

	virtual uint8_t readByte(uint16_t const addresss) const noexcept;
	virtual void writeByte(uint16_t address, uint8_t const value) noexcept;

	uint16_t readWord(uint16_t const address) const noexcept;
	void writeWord(uint16_t address, uint16_t const value) noexcept;

	void pushByte(uint8_t const value) noexcept;
	uint8_t popByte() noexcept;
	void pushWord(uint16_t const value) noexcept;
	uint16_t popWord() noexcept;

public:
	void sendReset() noexcept;
	void sendNmi() noexcept;
	void sendIrq() noexcept;
	void step() noexcept;

	Mos6502() noexcept;
};
