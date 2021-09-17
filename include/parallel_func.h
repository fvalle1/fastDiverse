#ifndef PARALLEL_FUNC_H
#define PARALLEL_FUNC_H

#include <mutex>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <queue>
#include <thread>

#include "mutex_wrapper.h"


static std::mutex buffer_mtx;

template <typename T>
void append_diversity(std::vector<T> &data, T value)
{
    if (std::find(data.begin(), data.end(), value) == data.end())
    {
        data.push_back(value);
    }
}

template <typename T>
void parseRow(std::queue<std::string> &buffer, std::vector<std::vector<T>> &diversities, std::vector<mutex_wrapper> &diversities_mtx, bool &ended)
{
    std::string entry;
    std::string line;
    while ((!ended) || (buffer.size() > 0)) // if there is something to parse and reader is reading
    {
        buffer_mtx.lock();
        if (buffer.size() > 0)
        {
            // std::cerr<<buffer.size()<<std::endl;

            line = std::string(buffer.front());
            buffer.pop();

            buffer_mtx.unlock();

            std::stringstream ss(line);

            //index
            std::getline(ss, entry, ',');

            for (size_t i = 0; i < diversities.size(); i++)
            {
                std::getline(ss, entry, ',');
                {
                    std::lock_guard<std::mutex> lock(diversities_mtx[i]);
                    append_diversity<T>(diversities[i], static_cast<T>(std::stoi(entry)));
                }
            }
        }
        else
        {
            buffer_mtx.unlock();
            std::this_thread::sleep_for(std::chrono::nanoseconds(1));
        }
    }
}

#endif