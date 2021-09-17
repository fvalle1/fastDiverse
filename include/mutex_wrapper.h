#ifndef MUTEX_WRAP_H
#define MUTEX_WRAP_H

#include <mutex>


//useful to create a vector of std::mutex
struct mutex_wrapper : std::mutex
{
    mutex_wrapper() = default;
    mutex_wrapper(mutex_wrapper const &) noexcept : std::mutex() {}
    bool operator==(mutex_wrapper const &other) noexcept { return this == &other; }
};

#endif