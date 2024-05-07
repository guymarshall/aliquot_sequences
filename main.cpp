#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#include "factors.hpp"
#include "number-of-steps.hpp"

#include <boost/multiprecision/cpp_int.hpp>

// constinit boost::multiprecision::cpp_int user_input = 138;
constinit boost::multiprecision::cpp_int user_input = 276;

int main() {
    boost::multiprecision::cpp_int number_of_steps = get_number_of_steps(user_input);
    std::cout << "Number of steps for " << user_input << ": " << number_of_steps << std::endl;

    return 0;
}