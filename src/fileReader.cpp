#include "fileReader.h"

#include <iostream>

void readRow(std::ifstream &file, int &readRows, std::queue<std::string> &buffer, bool &ended)
{
    std::string line;
    while (std::getline(file, line))
    {
        buffer.push(std::string(line));
        readRows++;
    }

    ended = true;
}