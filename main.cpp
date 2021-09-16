#include <fstream>
#include <string>

#include "reader.cpp"

int main(int argc, char *argv[])
{

    if(argc > 1) {
    loadFile<int>(argv[1]);
    }else{
        std::cerr << "No file specified" << std::endl;
    }


    return 0;
}