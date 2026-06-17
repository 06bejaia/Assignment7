#pragma once

#include <vector>
#include <cstdint>
#include <string>

class MiniGPURuntime
{
public:
    MiniGPURuntime(int num_cores, int threads_per_block);

    void loadProgram(const std::vector<uint16_t>& program);
    void launch(int total_threads);
    void printLaunchInfo() const;

private:
    int num_cores;
    int threads_per_block;
    int total_threads;
    int total_blocks;

    std::vector<uint16_t> program;
};