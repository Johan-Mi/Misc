#include <cstdlib>
#include <iostream>
#include <stdint.h>

#include "mos6502.hpp"

Mos6502::MemLocation::MemLocation(uint16_t const a) : address(a) {}
[[nodiscard]] constexpr Mos6502::MemLocation::operator uint16_t const &(
) const noexcept {
    return address;
}

constexpr uint8_t Mos6502::read(uint8_t const location) const noexcept {
    return location;
}
inline uint8_t Mos6502::read(MemLocation const location) const noexcept {
    return readByte(location);
}
inline void Mos6502::write(uint8_t &location, uint8_t const value) noexcept {
    location = value;
}
inline void Mos6502::write(MemLocation location, uint8_t const value) noexcept {
    writeByte(location, value);
}

void Mos6502::movGeneric(auto const src, auto dest) noexcept {
    uint8_t val = read(src);
    flags.Z = !val;
    flags.N = val >> 7;
    write(dest, val);
}

// Branches
#define O(NAME, COND)                                                          \
    bool Mos6502::NAME(int8_t const value) noexcept {                          \
        if (COND)                                                              \
            PC += value;                                                       \
        return COND;                                                           \
    }

O(BCC, !flags.C); // BCC
O(BCS, +flags.C); // BCS
O(BEQ, +flags.Z); // BEQ
O(BMI, +flags.N); // BMI
O(BNE, !flags.Z); // BNE
O(BPL, !flags.N); // BPL
O(BVC, +flags.V); // BVC
O(BVS, !flags.V); // BVS
#undef O

// Clear flags
#define O(FLAG)                                                                \
    inline void Mos6502::CL##FLAG() noexcept {                                 \
        flags.FLAG = 0;                                                        \
    }

O(C); // CLC
O(D); // CLD
O(I); // CLI
O(V); // CLV
#undef O

// Set flags
#define O(FLAG)                                                                \
    inline void Mos6502::SE##FLAG() noexcept {                                 \
        flags.FLAG = 1;                                                        \
    }

O(C); // SEC
O(D); // SED
O(I); // SEI
#undef O

// Comparisions
#define O(NAME, REG)                                                           \
    void Mos6502::NAME(auto const location) noexcept {                         \
        uint8_t val = read(location);                                          \
        flags.Z = REG == val;                                                  \
        flags.N = (REG - val) >> 7;                                            \
        flags.C = val > REG;                                                   \
    }

O(CMP, A); // CMP
O(CPX, X); // CPX
O(CPY, Y); // CPY
#undef O

// Loads
#define O(REG)                                                                 \
    inline void Mos6502::LD##REG(auto const location) noexcept {               \
        movGeneric(location, REG);                                             \
    }

O(A); // LDA
O(X); // LDX
O(Y); // LDY
#undef O

// Stores
#define O(REG)                                                                 \
    inline void Mos6502::ST##REG(auto location) noexcept {                     \
        write(location, REG);                                                  \
    }

O(A); // STA
O(X); // STX
O(Y); // STY
#undef O

// Transfers
#define O(SRC, DEST)                                                           \
    inline void Mos6502::T##SRC##DEST() noexcept {                             \
        movGeneric(SRC, DEST);                                                 \
    }

O(A, X); // TAX
O(A, Y); // TAY
O(S, X); // TSX
O(X, A); // TXA
O(X, S); // TXS
O(Y, A); // TYA
#undef O

void Mos6502::ADC(auto const location) noexcept {
    // TODO: Add support for decimal mode
    uint8_t val = read(location);
    uint16_t sum = A + val + flags.C;
    flags.C = sum > 0xff;
    flags.V = ~(A ^ val) & (A ^ sum) & 0x80;
    A = sum;
    flags.Z = !A;
    flags.N = A >> 7;
}
void Mos6502::AND(auto const location) noexcept {
    A &= read(location);
    flags.Z = !A;
    flags.N = A >> 7;
}
void Mos6502::ASL(auto const location) noexcept {
    uint8_t val = read(location);
    flags.C = val >> 7;
    flags.Z = !val;
    flags.N = val >> 7;
    write(location, val << 1);
}
void Mos6502::BIT(auto const location) noexcept {
    uint8_t result = A & read(location);
    flags.Z = !result;
    flags.N = result >> 7;
    flags.V = (result >> 6) & 1;
}
void Mos6502::BRK() noexcept {
    pushWord(PC);
    pushByte(flags.raw);
    PC = readWord(0xffff);
}
void Mos6502::DEC(auto location) noexcept {
    uint8_t val = read(location) - 1;
    flags.Z = !val;
    flags.N = val >> 7;
    write(location, val);
}
inline void Mos6502::DEX() {
    DEC(X);
}
inline void Mos6502::DEY() {
    DEC(Y);
}
void Mos6502::EOR(auto const location) noexcept {
    A ^= read(location);
    flags.Z = !A;
    flags.N = A >> 7;
}
void Mos6502::INC(auto location) noexcept {
    uint8_t val = read(location) + 1;
    flags.Z = !val;
    flags.N = val >> 7;
    write(location, val);
}
inline void Mos6502::INX() {
    INC(X);
}
inline void Mos6502::INY() {
    INC(Y);
}
inline void Mos6502::JMP(uint16_t const value) noexcept {
    PC = value;
}
void Mos6502::JSR(uint16_t const value) noexcept {
    pushWord(PC + 1);
    JMP(value);
}
void Mos6502::LSR(auto location) noexcept {
    uint8_t val = read(location);
    flags.C = val;
    flags.N = 0;
    flags.Z = !val;
    write(location, val >> 1);
}
void Mos6502::ORA(auto const location) noexcept {
    A |= read(location);
    flags.Z = !A;
    flags.N = A >> 7;
}
inline void Mos6502::PHA() noexcept {
    pushByte(A);
}
inline void Mos6502::PHP() noexcept {
    pushByte(flags.raw);
}
inline void Mos6502::PLA() noexcept {
    A = popByte();
}
inline void Mos6502::PLP() noexcept {
    flags.raw = popByte();
}
void Mos6502::ROL(auto location) noexcept {
    uint8_t val = read(location);
    bool oldCarry = flags.C;
    flags.C = flags.N = val >> 7;
    flags.Z = !(val & 0x7f);
    write(location, val << 1 | oldCarry);
}
void Mos6502::ROR(auto location) noexcept {
    uint8_t val = read(location);
    bool oldCarry = flags.C;
    flags.C = val;
    val = val >> 1 | oldCarry << 7;
    flags.N = val >> 7;
    flags.Z = !val;
    write(location, val);
}
void Mos6502::RTI() noexcept {
    flags.raw = popByte();
    PC = popWord();
}
void Mos6502::RTS() noexcept {
    PC = popWord() + 1;
}
void Mos6502::SBC(auto const location) noexcept {
    ADC(~read(location));
}

void Mos6502::sendReset() noexcept {
    flags.B = 1;
    flags.D = 0;
    flags.I = 1;
    flags._ = 1;
    PC = readWord(0xfffc);
    S = 0xff;
}
void Mos6502::sendNmi() noexcept {
    pushWord(PC);
    pushByte(flags.raw & 0b11101111);
    PC = readWord(0xffff);
}
void Mos6502::sendIrq() noexcept {
    if (!flags.I) {
        pushWord(PC);
        pushByte(flags.raw & 0b11101111);
        PC = readWord(0xffff);
    }
}

uint8_t Mos6502::readByte(uint16_t const addresss) const noexcept {
    std::cerr << "readByte()' has to be overridden in a derived class\n";
    exit(1);
}
void Mos6502::writeByte(uint16_t address, uint8_t const value) noexcept {
    std::cerr << "writeByte() has to be overridden in a derived class\n";
    exit(1);
}

uint16_t Mos6502::readWord(uint16_t const address) const noexcept {
    return static_cast<uint16_t>(readByte(address + 1)) << 8 |
           readByte(address);
}
void Mos6502::writeWord(uint16_t address, uint16_t const value) noexcept {
    writeByte(address, value);
    writeByte(address + 1, value >> 8);
}

inline void Mos6502::pushByte(uint8_t const value) noexcept {
    writeByte(S--, value);
}
inline uint8_t Mos6502::popByte() noexcept {
    return readByte(++S);
}
void Mos6502::pushWord(uint16_t const value) noexcept {
    pushByte(value >> 8);
    pushByte(value);
}
uint16_t Mos6502::popWord() noexcept {
    return popByte() | static_cast<uint16_t>(popByte()) << 8;
}

[[nodiscard]] Mos6502::MemLocation Mos6502::opImm() const noexcept {
    return PC + 1;
}
Mos6502::MemLocation Mos6502::opZpg() const noexcept {
    return readByte(PC + 1);
}
Mos6502::MemLocation Mos6502::opAbs() const noexcept {
    return readWord(PC + 1);
}
Mos6502::MemLocation Mos6502::opAbsX() const noexcept {
    return readWord(PC + 1) + X;
}
Mos6502::MemLocation Mos6502::opAbsY() const noexcept {
    return readWord(PC + 1) + Y;
}
Mos6502::MemLocation Mos6502::opXInd() const noexcept {
    return readWord((readByte(PC + 1) + X) & 0xff);
}
Mos6502::MemLocation Mos6502::opIndY() const noexcept {
    return readWord(readByte(PC + 1)) + Y;
}
Mos6502::MemLocation Mos6502::opInd() const noexcept {
    return readWord(readWord(PC + 1));
}
Mos6502::MemLocation Mos6502::opZpgX() const noexcept {
    return (readByte(PC + 1) + X) & 0xff;
}
Mos6502::MemLocation Mos6502::opZpgY() const noexcept {
    return (readByte(PC + 1) + Y) & 0xff;
}

void Mos6502::step() noexcept {
    switch (uint8_t opcode = readByte(PC); opcode) {
    case 0x00: // BRK
        BRK();
        break;
    case 0x01: // ORA X,ind
        ORA(opXInd());
        PC += 3;
        break;
    case 0x05: // ORA zpg
        ORA(opZpg());
        PC += 2;
        break;
    case 0x06: // ASL zpg
        ASL(opZpg());
        PC += 2;
        break;
    case 0x08: // PHP
        PHP();
        PC++;
        break;
    case 0x09: // ORA #
        ORA(opImm());
        PC += 2;
        break;
    case 0x0a: // ASL A
        ASL(A);
        PC++;
        break;
    case 0x0d: // ORA abs
        ORA(opAbs());
        PC += 3;
        break;
    case 0x0e: // ASL abs
        ASL(opAbs());
        PC += 3;
        break;
    case 0x10: // BPL rel
        BPL(readByte(PC + 1));
        PC += 2;
        break;
    case 0x11: // ORA ind,y
        ORA(opIndY());
        PC += 2;
        break;
    case 0x15: // ORA zpg,X
        ORA(opZpgX());
        PC += 2;
        break;
    case 0x16: // ASL zpg,X
        ASL(opZpgX());
        PC += 2;
        break;
    case 0x18: // CLC
        CLC();
        PC++;
        break;
    case 0x19: // ORA abs,Y
        ORA(opAbsY());
        PC += 3;
        break;
    case 0x1d: // ORA abs,X
        ORA(opAbsX());
        PC += 3;
        break;
    case 0x1e: // ASL abs,X
        ASL(opAbsX());
        PC += 3;
        break;
    case 0x20: // JSR abs
        JSR(opAbs());
        break;
    case 0x21: // AND X,ind
        AND(opXInd());
        PC += 2;
        break;
    case 0x24: // BIT zpg
        BIT(opZpg());
        PC += 2;
        break;
    case 0x25: // AND zpg
        AND(opZpg());
        PC += 2;
        break;
    case 0x26: // ROL zpg
        ROL(opZpg());
        PC += 2;
        break;
    case 0x28: // PLP
        PLP();
        PC++;
        break;
    case 0x29: // AND #
        AND(opImm());
        PC += 2;
        break;
    case 0x2a: // ROL A
        ROL(A);
        PC++;
        break;
    case 0x2c: // BIT abs
        BIT(opAbs());
        PC += 3;
        break;
    case 0x2d: // AND abs
        AND(opAbs());
        PC += 3;
        break;
    case 0x2e: // ROL abs
        ROL(opAbs());
        PC += 3;
        break;
    case 0x30: // BMI rel
        BMI(readByte(PC + 1));
        PC += 2;
        break;
    case 0x31: // AND ind,Y
        AND(opIndY());
        PC += 2;
        break;
    case 0x35: // AND zpg,X
        AND(opZpgX());
        PC += 2;
        break;
    case 0x36: // ROL zpg,X
        ROL(opZpgX());
        PC += 2;
        break;
    case 0x38: // SEC
        SEC();
        PC++;
        break;
    case 0x39: // AND abs,Y
        AND(opAbsY());
        PC += 3;
        break;
    case 0x3d: // AND abs,X
        AND(opAbsX());
        PC += 3;
        break;
    case 0x3e: // LSR abs
        LSR(opAbs());
        PC += 3;
        break;
    case 0x40: // RTI
        RTI();
        PC++;
        break;
    case 0x41: // EOR X,ind
        EOR(opXInd());
        PC += 2;
        break;
    case 0x45: // EOR zpg
        EOR(opZpg());
        PC += 2;
        break;
    case 0x46: // LSR zpg
        LSR(opZpg());
        PC += 2;
        break;
    case 0x48: // PHA
        PHA();
        PC++;
        break;
    case 0x49: // EOR #
        EOR(opImm());
        PC += 2;
        break;
    case 0x4a: // LSR A
        LSR(A);
        PC++;
        break;
    case 0x4c: // JMP abs
        JMP(opAbs());
        PC += 3;
        break;
    case 0x4d: // EOR abs
        EOR(opAbs());
        PC += 3;
        break;
    case 0x4e: // LSR abs
        LSR(opAbs());
        PC += 3;
        break;
    case 0x50: // BVC rel
        BVC(readByte(PC + 1));
        PC += 2;
        break;
    case 0x51: // EOR ind,Y
        EOR(opIndY());
        PC += 2;
        break;
    case 0x55: // EOR zpg,X
        EOR(opZpgX());
        PC += 2;
        break;
    case 0x56: // LSR zpg,X
        LSR(opZpgX());
        PC += 2;
        break;
    case 0x58: // CLI
        CLI();
        PC++;
        break;
    case 0x59: // EOR abs,Y
        EOR(opAbsY());
        PC += 3;
        break;
    case 0x5d: // EOR abs,X
        EOR(opAbsX());
        PC += 3;
        break;
    case 0x5e: // LSR abs,X
        LSR(opAbsX());
        PC += 3;
        break;
    case 0x60: // RTS
        RTS();
        PC++;
        break;
    case 0x61: // ADC X,ind
        ADC(opXInd());
        PC += 2;
        break;
    case 0x65: // ADC zpg
        ADC(opZpg());
        PC += 2;
        break;
    case 0x66: // ROR zpg
        ROR(opZpg());
        PC += 2;
        break;
    case 0x68: // PLA
        PLA();
        PC++;
        break;
    case 0x69: // ADC #
        ADC(opImm());
        PC += 2;
        break;
    case 0x6a: // ROR A
        ROR(A);
        PC++;
        break;
    case 0x6c: // JMP ind
        JMP(opInd());
        PC += 3;
        break;
    case 0x6d: // ADC abs
        ADC(opAbs());
        PC += 3;
        break;
    case 0x6e: // ROR abs
        ROR(opAbs());
        PC += 3;
        break;
    case 0x70: // BVS rel
        BVS(readByte(PC + 1));
        PC += 2;
        break;
    case 0x71: // ADC ind,Y
        ADC(opIndY());
        PC += 2;
        break;
    case 0x75: // ADC zpg,X
        ADC(opZpgX());
        PC += 2;
        break;
    case 0x76: // ROR zpg,X
        ROR(opZpgX());
        PC += 2;
        break;
    case 0x78: // SEI
        SEI();
        PC++;
        break;
    case 0x79: // ADC abs,Y
        ADC(opAbsY());
        PC += 3;
        break;
    case 0x7d: // ADC abs,X
        ADC(opAbsX());
        PC += 3;
        break;
    case 0x7e: // ROR abs,X
        ROR(opAbsX());
        PC += 3;
        break;
    case 0x81: // STA X,ind
        STA(opXInd());
        PC += 2;
        break;
    case 0x84: // STY zpg
        STY(opZpg());
        PC += 2;
        break;
    case 0x85: // STA zpg
        STA(opZpg());
        PC += 2;
        break;
    case 0x86: // STX zpg
        STX(opZpg());
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
        STY(opAbs());
        PC += 3;
        break;
    case 0x8d: // STA abs
        STA(opAbs());
        PC += 3;
        break;
    case 0x8e: // STX abs
        STX(opAbs());
        PC += 3;
        break;
    case 0x90: // BCC rel
        BCC(readByte(PC + 1));
        PC += 2;
        break;
    case 0x91: // STA ind,Y
        STA(opIndY());
        PC += 2;
        break;
    case 0x94: // STY zpg,X
        STY(opZpgX());
        PC += 2;
        break;
    case 0x95: // STA zpg,X
        STA(opZpgX());
        PC += 2;
        break;
    case 0x96: // STA zpg,Y
        STA(opZpgY());
        PC += 2;
        break;
    case 0x98: // TYA
        TYA();
        PC++;
        break;
    case 0x99: // STA abs,Y
        STA(opAbsY());
        PC += 3;
        break;
    case 0x9a: // TXS
        TXS();
        PC++;
        break;
    case 0x9d: // STA abs,X
        STA(opAbsX());
        PC += 3;
        break;
    case 0xa0: // LDY #
        LDY(opImm());
        PC += 2;
        break;
    case 0xa1: // LDA X,ind
        LDA(opXInd());
        PC += 2;
        break;
    case 0xa2: // LDX #
        LDX(opImm());
        PC += 2;
        break;
    case 0xa4: // LDY zpg
        LDY(opZpg());
        PC += 2;
        break;
    case 0xa5: // LDA zpg
        LDA(opZpg());
        PC += 2;
        break;
    case 0xa6: // LDX zpg
        LDX(opZpg());
        PC += 2;
        break;
    case 0xa8: // TAY
        TAY();
        PC++;
        break;
    case 0xa9: // LDA #
        LDA(opImm());
        PC += 2;
        break;
    case 0xaa: // TAX
        TAX();
        PC++;
        break;
    case 0xac: // LDY abs
        LDY(opAbs());
        PC += 3;
        break;
    case 0xad: // LDA abs
        LDA(opAbs());
        PC += 3;
        break;
    case 0xae: // LDX abs
        LDX(opAbs());
        PC += 3;
        break;
    case 0xb0: // BCS rel
        BCS(readByte(PC + 1));
        PC += 2;
        break;
    case 0xb1: // LDA ind,Y
        LDA(opIndY());
        PC += 2;
        break;
    case 0xb4: // LDY zpg,X
        LDY(opZpgX());
        PC += 2;
        break;
    case 0xb5: // LDA zpg,X
        LDA(opZpgX());
        PC += 2;
        break;
    case 0xb6: // LDX zpg,Y
        LDX(opZpgY());
        PC += 2;
        break;
    case 0xb8: // CLV
        CLV();
        PC++;
        break;
    case 0xb9: // LDA abs,Y
        LDA(opAbsY());
        PC += 3;
        break;
    case 0xba: // TSX
        TSX();
        PC++;
        break;
    case 0xbc: // LDY abs,X
        LDY(opAbsX());
        PC += 3;
        break;
    case 0xbd: // LDA abs,X
        LDA(opAbsX());
        PC += 3;
        break;
    case 0xbe: // LDX abs,Y
        LDX(opAbsY());
        PC += 3;
        break;
    case 0xc0: // CPY #
        CPY(opImm());
        PC += 2;
        break;
    case 0xc1: // CMP X,ind
        CMP(opXInd());
        PC += 2;
        break;
    case 0xc4: // CPY zpg
        CPY(opZpg());
        PC += 2;
        break;
    case 0xc5: // CMP zpg
        CMP(opZpg());
        PC += 2;
        break;
    case 0xc6: // DEC zpg
        DEC(opZpg());
        PC += 2;
        break;
    case 0xc8: // INY
        INY();
        PC++;
        break;
    case 0xc9: // CMP #
        CMP(opImm());
        PC += 2;
        break;
    case 0xca: // DEX
        DEX();
        PC++;
        break;
    case 0xcc: // CPY abs
        CPY(opAbs());
        PC += 3;
        break;
    case 0xcd: // CMP abs
        CMP(opAbs());
        PC += 3;
        break;
    case 0xce: // DEC abs
        DEC(opAbs());
        PC += 3;
        break;
    case 0xd0: // BNE rel
        BNE(readByte(PC + 1));
        PC += 2;
        break;
    case 0xd1: // CMP ind,Y
        CMP(opIndY());
        PC += 2;
        break;
    case 0xd5: // CMP zpg,X
        CMP(opZpgX());
        PC += 2;
        break;
    case 0xd6: // DEC zpg,X
        DEC(opZpgX());
        PC += 2;
        break;
    case 0xd8: // CLD
        CLD();
        PC++;
        break;
    case 0xd9: // CMP abs,Y
        CMP(opAbsY());
        PC += 3;
        break;
    case 0xdd: // CMP abs,X
        CMP(opAbsX());
        PC += 3;
        break;
    case 0xde: // DEC abs,X
        DEC(opAbsX());
        PC += 3;
        break;
    case 0xe0: // CPX #
        CPX(opImm());
        PC += 2;
        break;
    case 0xe1: // SBC X,ind
        SBC(opXInd());
        PC += 2;
        break;
    case 0xe4: // CPX zpg
        CPX(opZpg());
        PC += 2;
        break;
    case 0xe5: // SBC zpg
        SBC(opZpg());
        PC += 2;
        break;
    case 0xe6: // INC zpg
        INC(opZpg());
        PC += 2;
        break;
    case 0xe8: // INX
        INX();
        PC++;
        break;
    case 0xe9: // SBC #
        SBC(opImm());
        PC += 2;
        break;
    case 0xea: // NOP
        PC++;
        break;
    case 0xec: // CPX abs
        CPX(opAbs());
        PC += 3;
        break;
    case 0xed: // SBC abs
        SBC(opAbs());
        PC += 3;
        break;
    case 0xee: // INC abs
        INC(opAbs());
        PC += 3;
        break;
    case 0xf0: // BEQ rel
        BEQ(readByte(PC + 1));
        PC += 2;
        break;
    case 0xf1: // SBC ind,Y
        SBC(opIndY());
        PC += 2;
        break;
    case 0xf5: // SBC zpg,X
        SBC(opZpgX());
        PC += 2;
        break;
    case 0xf6: // INC zpg,X
        INC(opZpgX());
        PC += 2;
        break;
    case 0xf8: // SED
        SED();
        PC++;
        break;
    case 0xf9: // SBC abs,Y
        SBC(opAbsY());
        PC += 3;
        break;
    case 0xfd: // SBC abs,X
        SBC(opAbsX());
        PC += 3;
        break;
    case 0xfe: // INC abs,X
        INC(opAbsX());
        PC += 3;
        break;

    default: // Invalid
        std::cerr << "Invalid opcode: " << opcode << '\n';
        exit(1);
    }
}

Mos6502::Mos6502() noexcept {}
