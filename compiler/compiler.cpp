#include "compiler.h"
#include "isa.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <stdexcept>

std::vector<uint16_t> compile_file(const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Cannot open instruction file: " + filename);
    }

    std::vector<uint16_t> code;
    std::string line;
    int line_num = 0;

    while (std::getline(file, line)) {
        line_num++;

        if (line.empty())
            continue;

        if (line[0] == '#')
            continue;

        std::stringstream ss(line);
        std::string op;
        ss >> op;

        if (op.empty())
            continue;

        if (op == "CONST") {
            std::string rd;
            int imm;

            ss >> rd >> imm;

            code.push_back(
                encodeConst(parseReg(rd), (uint8_t)imm)
            );
        }
        else if (op == "ADD") {
            std::string rd, rs, rt;
            ss >> rd >> rs >> rt;

            code.push_back(
                encode3(parseReg(rd), parseReg(rs), parseReg(rt), ADD)
            );
        }
        else if (op == "SUB") {
            std::string rd, rs, rt;
            ss >> rd >> rs >> rt;

            code.push_back(
                encode3(parseReg(rd), parseReg(rs), parseReg(rt), SUB)
            );
        }
        else if (op == "MUL") {
            std::string rd, rs, rt;
            ss >> rd >> rs >> rt;

            code.push_back(
                encode3(parseReg(rd), parseReg(rs), parseReg(rt), MUL)
            );
        }
        else if (op == "DIV") {
            std::string rd, rs, rt;
            ss >> rd >> rs >> rt;

            code.push_back(
                encode3(parseReg(rd), parseReg(rs), parseReg(rt), DIV)
            );
        }
        else if (op == "LDR") {
            std::string rd, rs;
            ss >> rd >> rs;

            code.push_back(
                encode3(parseReg(rd), parseReg(rs), 0, LDR)
            );
        }
        else if (op == "STR") {
            std::string rs, rt;
            ss >> rs >> rt;

            code.push_back(
                encode3(0, parseReg(rs), parseReg(rt), STR)
            );
        }
        else if (op == "RET") {
            code.push_back(0xF000);
        }
        else if (op == "NOP") {
            code.push_back(0x0000);
        }
        else {
            throw std::runtime_error(
                "Unknown instruction on line "
                + std::to_string(line_num)
                + ": "
                + op
            );
        }
    }

    return code;
}

void print_program(const std::vector<uint16_t>& program)
{
    std::cout << "\nProgram bytecode:\n";

    for (size_t i = 0; i < program.size(); i++) {
        std::cout
            << "  PC " << i
            << " : 0x"
            << std::hex
            << std::setw(4)
            << std::setfill('0')
            << program[i]
            << std::dec
            << "\n";
    }

    std::cout << "\n";
}