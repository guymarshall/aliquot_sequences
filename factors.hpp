std::vector<uint64_t> get_factors(uint64_t number) {
    std::vector<uint64_t> factors; // TODO: calculate sum here instead of making vector
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