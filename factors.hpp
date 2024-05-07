#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

boost::multiprecision::cpp_int get_factor_sum(const boost::multiprecision::cpp_int& number) {
    boost::multiprecision::cpp_int factor_sum = 0;
    boost::multiprecision::cpp_int step = number % 2 == 0 ? 1 : 2;
    boost::multiprecision::cpp_int square_root = boost::multiprecision::sqrt(number);

    for (boost::multiprecision::cpp_int i = 1; i <= square_root; i += step) {
        if (number % i == 0) {
            factor_sum += i;
            factor_sum += number / i;
        }
    }

    factor_sum -= number;

    return factor_sum;
}