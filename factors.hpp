uint64_t get_factor_sum(const uint64_t number) {
    uint64_t factor_sum = 0;
    const uint64_t step = number % 2 == 0 ? 1 : 2;

    for (uint64_t i = 1; i <= std::sqrt(number); i += step) {
        if (number % i == 0) {
            factor_sum += (i);
            factor_sum += (number / i);
        }
    }

    factor_sum -= number;

    return factor_sum;
}