#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

namespace Random {
    int generate(int min, int max) {
        // Seed the random number generator with the current time
        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        // Generate and return a random number between min and max
        return min + std::rand() % (max - min + 1);
    }
}