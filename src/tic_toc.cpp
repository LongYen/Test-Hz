#include <ctime>
#include <cstdlib>
#include <chrono>
#include "test_package/tic_toc.h"


void TicToc::tic()
{
    start = std::chrono::system_clock::now();
}

double TicToc::toc()
{
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    return elapsed_seconds.count() * 1000;
}
