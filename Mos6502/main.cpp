#include "mos6502.hpp"

class MyMos6502 : Mos6502 {
	uint8_t readByte(uint16_t const address) const noexcept override {
		return memory[address];
	}

	void writeByte(uint16_t address, uint8_t const value) noexcept override {
		memory[address] = value;
	}

public:
	using Mos6502::Mos6502;

	uint8_t memory[65536] = {0};
};

int main() {
	MyMos6502 cpu;

	return 0;
}
