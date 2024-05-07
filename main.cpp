#include <iostream>
#include <chrono>
#include <cmath>
#include <vector>
#include <algorithm>

#include "factors.hpp"
#include "number-of-steps.hpp"

#include <boost/multiprecision/cpp_int.hpp>

constinit boost::multiprecision::cpp_int user_input = 138;
// constinit boost::multiprecision::cpp_int user_input = 276;

int main() {
    const std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    boost::multiprecision::cpp_int number_of_steps = get_number_of_steps(user_input);
    std::cout << "Number of steps for " << user_input << ": " << number_of_steps << std::endl;

    const std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    const std::chrono::duration<double> duration = end - begin;
    std::cout << "Duration: " << duration.count() << " seconds" << std::endl;

    return 0;
}