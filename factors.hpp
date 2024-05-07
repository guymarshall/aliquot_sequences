#include <boost/multiprecision/cpp_int.hpp>
#include <future>
#include <vector>

boost::multiprecision::cpp_int sum_factors_range(const boost::multiprecision::cpp_int& number, boost::multiprecision::cpp_int start, boost::multiprecision::cpp_int end, boost::multiprecision::cpp_int step) {
    boost::multiprecision::cpp_int range_sum = 0;

    for (boost::multiprecision::cpp_int i = start; i <= end; i += step) {
        if (number % i == 0) {
            range_sum += i;
            range_sum += number / i;
        }
    }

    return range_sum;
}

boost::multiprecision::cpp_int get_factor_sum(const boost::multiprecision::cpp_int& number) {
    boost::multiprecision::cpp_int factor_sum = 0;
    boost::multiprecision::cpp_int step = (number % 2 == 0) ? 1 : 2;
    boost::multiprecision::cpp_int square_root = boost::multiprecision::sqrt(number);

    const int num_threads = std::thread::hardware_concurrency();
    std::vector<std::future<boost::multiprecision::cpp_int>> futures;

    boost::multiprecision::cpp_int range_size = square_root / num_threads;

    for (int i = 0; i < num_threads; ++i) {
        boost::multiprecision::cpp_int start = i * range_size + 1;
        boost::multiprecision::cpp_int end = (i == num_threads - 1) ? square_root : (i + 1) * range_size;
        futures.emplace_back(std::async(std::launch::async, sum_factors_range, number, start, end, step));
    }

    for (auto& future : futures) {
        factor_sum += future.get();
    }

    factor_sum -= number;

    return factor_sum;
}