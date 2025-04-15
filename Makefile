# Makefile for Monte Carlo Pi Estimator in C++ using MPI

CXX = mpic++
CXXFLAGS = -O2 -std=c++11 -Wall
TARGET = montecarlo_pi_mpi

all: $(TARGET)

$(TARGET): montecarlo_pi_mpi.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) montecarlo_pi_mpi.cpp

clean:
	rm -f $(TARGET)
