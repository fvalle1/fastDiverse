#ifndef READER_H
#define READER_H

#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>

#include "parallel_func.h"
#include "fileReader.h"
#include "monitor.h"
#include "mutex_wrapper.h"

template <typename T>
void loadFile(const char *filename, int nThreads = 6, bool verbose = false, std::string out_filename = "diversity.csv")
{
    if (nThreads < 1)
        nThreads = 2;
    std::cout<< "Reding file[" << filename << "]" << std::endl;
    std::cout << "Using " << nThreads << " threads" << std::endl;
    std::ifstream file(filename, std::ios::in);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::vector<std::vector<T>> diversities;

    std::string line;
    std::vector<mutex_wrapper> diversities_mtx; //one per column

    //header
    std::string entry;

    std::getline(file, line);
    std::stringstream ss(line);
    std::getline(ss, entry, ',');
    while (std::getline(ss, entry, ','))
    {
        diversities.emplace_back(std::vector<T>());
        diversities_mtx.emplace_back(mutex_wrapper());
    }

    std::queue<std::string> bufferLines;

    bool ended = false;
    int readRows = 0;

    //Threads parse rows as soon as they are available in bufferLines
    std::thread parserThreads[nThreads];
    for (int iThread = 0; iThread < nThreads; iThread++)
    {
        parserThreads[iThread] = std::thread(parseRow<T>, std::ref(bufferLines), std::ref(diversities), std::ref(diversities_mtx), std::ref(ended));
    }

    //read lines from file and fill bufferLines
    std::thread(readRow, std::ref(file), std::ref(readRows), std::ref(bufferLines), std::ref(ended)).detach();
    
    //monitor status
    if (verbose)
    {
        std::thread(monitor<std::queue<std::string>, int>, std::ref(bufferLines), std::ref(readRows), std::ref(ended)).detach();
    }

    for (int iThread = 0; iThread < nThreads; iThread++)
    {
        parserThreads[iThread].join();
    }
    std::cout << std::endl
              << "Finished" << std::endl;

    while (!bufferLines.empty())
        bufferLines.pop(); //clear bufferLines to avoid memory leaks and monitor thread to stop

    // sum columns
    std::vector<long int> diversity_count;

    for (auto &diversity : diversities)
    {
        diversity_count.push_back(diversity.size());
        diversity.clear();
    }

    diversities.clear();


    // save to file
    std::ofstream outfile(out_filename, std::ios::out);

    for (auto &diversity : diversity_count)
    {
        outfile << diversity << std::endl;
    }

    outfile.close();
}

#endif