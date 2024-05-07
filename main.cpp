#include <iostream>
#include <chrono>
#include <cmath>
#include <vector>
#include <algorithm>

#include "factors.hpp"
#include "number-of-steps.hpp"

int main() {
    const std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    uint64_t user_input = 138;
    // uint64_t user_input = 276;
    uint64_t number_of_steps = get_number_of_steps(user_input);
    std::cout << "Number of steps for " << user_input << ": " << number_of_steps << std::endl;

    const std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    const std::chrono::duration<double> duration = end - begin;
    std::cout << "Duration: " << duration.count() << " seconds" << std::endl;

    return 0;
}
