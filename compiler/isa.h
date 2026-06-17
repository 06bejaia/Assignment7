#pragma once
#include <cstdint>
#include <string>
#include <stdexcept>

enum Opcode {
    NOP   = 0x0,
    BRNZP = 0x1,
    CMP   = 0x2,
    ADD   = 0x3,
    SUB   = 0x4,
    MUL   = 0x5,
    DIV   = 0x6,
    LDR   = 0x7,
    STR   = 0x8,
    CONST = 0x9,
    RET   = 0xF
};

inline uint16_t encode3(uint8_t rd, uint8_t rs, uint8_t rt, Opcode op)
{
    return (op << 12) | (rd << 8) | (rs << 4) | rt;
}

inline uint16_t encodeConst(uint8_t rd, uint8_t imm)
{
    return (CONST << 12) | (rd << 8) | imm;
}

inline uint8_t parseReg(const std::string& r)
{
    if (r.size() < 2 || r[0] != 'R')
        throw std::runtime_error("Bad register: " + r);

    int v = std::stoi(r.substr(1));

    if (v < 0 || v > 15)
        throw std::runtime_error("Register out of range: " + r);

    return (uint8_t)v;
}