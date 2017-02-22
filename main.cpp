#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdint>
#include <stdexcept>

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

    size_t *data1 = new size_t[maxCount];
    size_t *data2 = new size_t[maxCount];

    for (size_t count = 0; count < maxCount; ++count)
    {
        clflush_func(&data1[count], &data2[count]);
    }

    delete [] data1;
    delete [] data2;

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
