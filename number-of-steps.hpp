#include <vector>
#include <algorithm>

uint64_t get_number_of_steps(const uint64_t number) {
    uint64_t step = 1;
    uint64_t sum_of_factors = get_factor_sum(number);
    std::vector<uint64_t> sums;

    while (sum_of_factors != 1) {
        if (std::find(sums.begin(), sums.end(), sum_of_factors) != sums.end()) {
            break;
        }

        step++;

        sums.push_back(sum_of_factors);
        sum_of_factors = get_factor_sum(sum_of_factors);

        std::cout << step << ": " << sum_of_factors << std::endl;
    }

    return step;
}