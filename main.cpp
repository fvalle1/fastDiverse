#include <fstream>
#include <string>

#include "reader.h"

int main(int argc, char *argv[])
{

    if (argc > 1)
    {
        int nThreads = 4;
        if (argc > 2)
            nThreads = std::atoi(argv[2]);
        loadFile<int>(argv[1], nThreads, true);
    }
    else
    {
        std::cerr << "No file specified" << std::endl;
    }

    return 0;
}