#include <vector>
#include <algorithm>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

boost::multiprecision::cpp_int get_number_of_steps(const boost::multiprecision::cpp_int& number) {
    boost::multiprecision::cpp_int step = 1;
    boost::multiprecision::cpp_int sum_of_factors = get_factor_sum(number);
    std::vector<boost::multiprecision::cpp_int> sums;

    while (sum_of_factors != 1) {
        if (std::find(sums.begin(), sums.end(), sum_of_factors) != sums.end()) {
            std::cout << "Loop found at step " << step << " for number " << number << std::endl;
            break;
        }

        step++;
        sums.push_back(sum_of_factors);
        sum_of_factors = get_factor_sum(sum_of_factors);

        std::cout << step << ": " << sum_of_factors << std::endl;
    }

    return step;
}