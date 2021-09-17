#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>
#include <queue>
#include <string>

void readRow(std::ifstream &file, int &readRows, std::queue<std::string> &buffer, bool &ended);
#endif
