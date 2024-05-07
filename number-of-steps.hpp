#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <boost/multiprecision/cpp_int.hpp>
#include "read-file.hpp"

boost::multiprecision::cpp_int get_number_of_steps(const boost::multiprecision::cpp_int& number) {
    std::string filename = "results/" + number.str() + ".csv";
    auto [step, sum_of_factors] = read_file_data(filename);

    if (sum_of_factors == 1) {
        std::cout << "Number: " << number << " has already been calculated." << std::endl;
        return step;
    }

    std::ofstream outfile(filename, std::ios::app);

    if (step == 1) {
        sum_of_factors = get_factor_sum(number);
        outfile << step << "," << sum_of_factors << '\n';
        outfile.flush(); // Ensure data is written immediately
    }

    std::vector<boost::multiprecision::cpp_int> sums;
    while (sum_of_factors != 1) {
        if (std::find(sums.begin(), sums.end(), sum_of_factors) != sums.end()) {
            std::cout << "Loop found at step " << step << " for number " << number << std::endl;
            break;
        }

        step++;
        sums.push_back(sum_of_factors);
        sum_of_factors = get_factor_sum(sum_of_factors);

        outfile << step << "," << sum_of_factors << '\n';
        outfile.flush(); // Ensure data is written immediately

        std::cout << step << ": " << sum_of_factors << std::endl;
    }

    outfile.close();
    return step;
}