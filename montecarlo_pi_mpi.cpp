#include <iostream>
#include <cstdlib>
#include <ctime>
#include <mpi.h>
#include <chrono>

int main(int argc, char *argv[]) {
    int rank, size;
    long long int total_points = 100000000; // Total number of random points
    long long int points_per_process;
    int local_count = 0, total_count = 0;

    // Initialize MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Rank of current process
    MPI_Comm_size(MPI_COMM_WORLD, &size); // Total number of processes

    points_per_process = total_points / size;

    // Seed the random number generator differently for each process
    unsigned int seed = static_cast<unsigned int>(time(0)) + rank * 1000;

    // Start time for root process
    std::chrono::high_resolution_clock::time_point start;
    if (rank == 0) {
        start = std::chrono::high_resolution_clock::now();
    }

    // Monte Carlo loop
    for (long long int i = 0; i < points_per_process; ++i) {
        double x = static_cast<double>(rand_r(&seed)) / RAND_MAX;
        double y = static_cast<double>(rand_r(&seed)) / RAND_MAX;
        if ((x * x + y * y) <= 1.0)
            local_count++;
    }

    // Reduce all local_counts into total_count at root process
    MPI_Reduce(&local_count, &total_count, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Root process estimates Pi
    if (rank == 0) {
        double pi_estimate = 4.0 * static_cast<double>(total_count) / static_cast<double>(total_points);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;

        std::cout << "Estimated Pi = " << pi_estimate << " using " << total_points << " points" << std::endl;
        std::cout << "Elapsed time = " << elapsed_seconds.count() << " seconds" << std::endl;
    }

    // Finalize MPI
    MPI_Finalize();
    return 0;
}
