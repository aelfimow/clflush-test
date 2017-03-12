#include <iostream>
#include <sstream>
#include <vector>
#include "scoped_chrono.h"

static_assert(sizeof(size_t) == 8, "size_t expected to be 64 bit");

extern "C" void clflush_func(void *p1, void *p2);

int main(int argc, char *argv[])
try
{
    if (argc != 3)
    {
        throw std::invalid_argument("Usage: maxSteps maxWords");
    }

    size_t maxSteps = 0;
    {
        std::stringstream ss { argv[1] };
        ss >> maxSteps;
    }

    size_t maxWords = 0;
    {
        std::stringstream ss { argv[2] };
        ss >> maxWords;
    }

    std::cout << "Max. steps: " << maxSteps << std::endl;
    std::cout << "Max. words: " << maxWords << std::endl;

    std::vector<size_t> data1(maxWords);
    std::vector<size_t> data2(maxWords);

    for (size_t step = 0; step < maxSteps; ++step)
    {
        std::cout << "Step: " << step << std::endl;
        {
            scoped_chrono sc { "Duration (d1, d2): " };

            for (auto &d1: data1)
            {
                for (auto &d2: data2)
                {
                    clflush_func(&d1, &d2);
                }
            }
        }

        {
            scoped_chrono sc { "Duration (d2, d1): " };

            for (auto &d2: data2)
            {
                for (auto &d1: data1)
                {
                    clflush_func(&d1, &d2);
                }
            }
        }
    }

    return EXIT_SUCCESS;
}
catch (std::exception &exc)
{
    std::cerr << "Exception: " << exc.what() << std::endl;
    return EXIT_FAILURE;
}
catch (...)
{
    std::cerr << "Error: exception" << std::endl;
    return EXIT_FAILURE;
}
