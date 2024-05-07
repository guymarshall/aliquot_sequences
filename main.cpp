#include <iostream>
#include <chrono>
#include <cmath>
#include <vector>

std::vector<uint64_t> get_factors(uint64_t number) {
    std::vector<uint64_t> factors;
    uint64_t step = number % 2 == 0 ? 1 : 2;

    for (uint64_t i = 1; i <= std::sqrt(number); i += step) {
        if (number % i == 0) {
            factors.push_back(i);
            factors.push_back(number / i);
        }
    }

    std::sort(factors.begin(), factors.end());
    factors.pop_back();

    return factors;
}

uint64_t factor_sum(std::vector<uint64_t> factors) {
    uint64_t result = 0;

    for (uint64_t factor : factors) {
        result += factor;
    }

    return result;
}

uint64_t get_number_of_steps(uint64_t number)
{
    uint64_t step = 1;
    std::vector<uint64_t> factors = get_factors(number);
    uint64_t sum_of_factors = factor_sum(factors);
    std::vector<uint64_t> sums;

    while (sum_of_factors != 1)
    {
        if (std::find(sums.begin(), sums.end(), sum_of_factors) != sums.end())
        {
            break;
        }

        step++;

        sums.push_back(sum_of_factors);
        factors = get_factors(sum_of_factors);
        sum_of_factors = factor_sum(factors);

        std::cout << step << ": " << sum_of_factors << std::endl;
    }

    return step;
}

int main()
{
    const std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    uint64_t user_input = 138;
    // uint64_t user_input = 276;
    uint64_t number_of_steps = get_number_of_steps(user_input);
    std::cout << "Number of steps for " << user_input << ": " << number_of_steps << std::endl;

    const std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    const std::chrono::duration<double> duration = end - begin;
    std::cout << "Duration: " << duration.count() << "seconds" << std::endl;

    return 0;
}
