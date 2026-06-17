#pragma once
#include <vector>
#include <cstdint>
#include <string>

std::vector<uint16_t> compile_file(const std::string& filename);
void print_program(const std::vector<uint16_t>& program);