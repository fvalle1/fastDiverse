#ifndef MONITOR_H
#define MONITOR_H

#include <iostream>
#include <chrono>
#include <thread>

using std::cout;
using std::cerr;
using std::endl;

template <typename TBuffer, typename T>
void monitor(const TBuffer &buffer, const T &total, bool &ended)
{
    while (!ended || buffer.size()>0)
    {
        cout << "\r" << buffer.size() << " row to parse out of " << total << "       ";
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    cout << endl;
}

#endif