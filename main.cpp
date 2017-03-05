#include <iostream>
#include <sstream>
#include <vector>
#include "scoped_chrono.h"

static_assert(sizeof(size_t) == 8, "size_t expected to be 64 bit");

extern "C" void clflush_func(void *p1, void *p2);

int main(int argc, char *argv[])
try
{
    if (argc != 2)
    {
        throw std::invalid_argument("Usage: maxCount");
    }

    size_t maxCount = 0;
    {
        std::stringstream ss1 { argv[1] };
        ss1 >> maxCount;
    }

    std::cout << "Max. count: " << maxCount << std::endl;

    std::vector<size_t> data1(maxCount);
    std::vector<size_t> data2(maxCount);

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
