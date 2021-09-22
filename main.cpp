#include <fstream>
#include <string>

#include "reader.h"

int main(int argc, char *argv[])
{

    if (argc > 1)
    {
        int nThreads = 4;
        auto out_filename = std::string("diversity_out.csv");

        if (argc > 2)
            nThreads = std::atoi(argv[2]);
        if (argc > 3)
            out_filename = argv[3];
        loadFile<int>(argv[1], nThreads, true, out_filename);
    }
    else
    {
        std::cerr << "No file specified" << std::endl;
    }

    return 0;
}