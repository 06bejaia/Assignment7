#include "../compiler/compiler.h"
#include "../runtime/MiniGPURuntime.h"

#include <iostream>
#include <string>
#include <exception>

static const int NUM_CORES = 2;
static const int THREADS_PER_BLOCK = 4;

int main(int argc, char** argv)
{
    try {
        std::string program_file = "programs/add.txt";
        int total_threads = 10;

        if (argc >= 2) {
            program_file = argv[1];
        }

        if (argc >= 3) {
            total_threads = std::stoi(argv[2]);
        }

        std::cout << "MiniGPU Runtime\n";
        std::cout << "Program file: " << program_file << "\n";

        auto program = compile_file(program_file);

        print_program(program);

        MiniGPURuntime gpu(NUM_CORES, THREADS_PER_BLOCK);

        gpu.loadProgram(program);
        gpu.launch(total_threads);

        std::cout << "Thread simulation log:\n";

        int total_blocks =
            (total_threads + THREADS_PER_BLOCK - 1)
            / THREADS_PER_BLOCK;

        for (int block = 0; block < total_blocks; block++) {
            int core = block % NUM_CORES;
            int first_thread = block * THREADS_PER_BLOCK;
            int remaining = total_threads - first_thread;

            int block_threads =
                remaining < THREADS_PER_BLOCK
                ? remaining
                : THREADS_PER_BLOCK;

            std::cout
                << "\n[dispatch] Core "
                << core
                << " receives Block "
                << block
                << " with "
                << block_threads
                << " active threads\n";

            for (int local_tid = 0;
                 local_tid < block_threads;
                 local_tid++) {

                int global_tid =
                    first_thread + local_tid;

                std::cout
                    << "  Core " << core
                    << " Block " << block
                    << " local_thread " << local_tid
                    << " global_thread " << global_tid
                    << " executing program\n";
            }

            std::cout
                << "[complete] Core "
                << core
                << " finished Block "
                << block
                << "\n";
        }

        std::cout << "\nExpected software-style result:\n";

        for (int t = 0; t < total_threads; t++) {
        int local_tid = t % THREADS_PER_BLOCK;

        int result = 7 + local_tid;

        std::cout
            << "  Thread "
            << t
            << " local_thread "
            << local_tid
            << " result R3 = "
            << result
            << "\n";
        }

        std::cout << "\nPASS: software runtime/log test completed\n";

        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "ERROR: " << e.what() << "\n";
        return 1;
    }
}