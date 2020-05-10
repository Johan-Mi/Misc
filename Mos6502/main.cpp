#include <iostream>

#include "mos6502.hpp"

class MyMos6502 : public Mos6502 {
	uint8_t readByte(uint16_t const address) const noexcept override {
		std::clog << "readByte(" << address << ")\n";
		return memory[address];
	}

	void writeByte(uint16_t address, uint8_t const value) noexcept override {
		std::clog << "writeByte(" << address << ", " << value << ")\n";
		memory[address] = value;
	}

public:
	uint8_t memory[65536] = {0};

	MyMos6502() {
		sendReset();
	}
};

int main() {
	MyMos6502 cpu;

	return 0;
}
