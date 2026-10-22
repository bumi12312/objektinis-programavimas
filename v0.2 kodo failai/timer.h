#ifndef TIMER_H
#define TIMER_H

#include <chrono>

struct Timer {
    std::chrono::high_resolution_clock::time_point pradzia =
        std::chrono::high_resolution_clock::now();

    void reset() { pradzia = std::chrono::high_resolution_clock::now(); }

    double elapsed() const {
        return std::chrono::duration<double>(
            std::chrono::high_resolution_clock::now() - pradzia).count();
    }
};

#endif
