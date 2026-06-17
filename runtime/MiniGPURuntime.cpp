#include "MiniGPURuntime.h"

#include <iostream>
#include <algorithm>

MiniGPURuntime::MiniGPURuntime(int cores, int tpb)
    : num_cores(cores),
      threads_per_block(tpb),
      total_threads(0),
      total_blocks(0)
{
}

void MiniGPURuntime::loadProgram(const std::vector<uint16_t>& prog)
{
    program = prog;

    std::cout
        << "Loaded "
        << program.size()
        << " instructions\n";
}

void MiniGPURuntime::launch(int threads)
{
    total_threads = threads;

    total_blocks =
        (total_threads + threads_per_block - 1)
        / threads_per_block;

    std::cout
        << "Launching "
        << total_threads
        << " threads\n";

    printLaunchInfo();
}

void MiniGPURuntime::printLaunchInfo() const
{
    std::cout << "\n================ MiniGPU Launch ================\n";

    std::cout << "GPU config:\n";
    std::cout << "  NUM_CORES          = " << num_cores << "\n";
    std::cout << "  THREADS_PER_BLOCK = " << threads_per_block << "\n";
    std::cout << "  TOTAL_THREADS     = " << total_threads << "\n";
    std::cout << "  TOTAL_BLOCKS      = " << total_blocks << "\n";

    std::cout << "\nBlock layout:\n";

    for (int block = 0; block < total_blocks; block++) {
        int first_thread = block * threads_per_block;
        int remaining = total_threads - first_thread;
        int block_threads = std::min(remaining, threads_per_block);
        int last_thread = first_thread + block_threads - 1;

        std::cout
            << "  Block " << block
            << ": global threads "
            << first_thread
            << " to "
            << last_thread
            << "  count=" << block_threads
            << "\n";
    }

    std::cout << "\nExpected dispatch waves:\n";

    int block = 0;
    int wave = 0;

    while (block < total_blocks) {
        std::cout << "  Wave " << wave << ":\n";

        for (int core = 0;
             core < num_cores && block < total_blocks;
             core++, block++) {

            int first_thread = block * threads_per_block;
            int remaining = total_threads - first_thread;
            int block_threads = std::min(remaining, threads_per_block);

            std::cout
                << "    Core " << core
                << " -> Block " << block
                << " with "
                << block_threads
                << " threads\n";
        }

        wave++;
    }

    std::cout << "================================================\n\n";
}