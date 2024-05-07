#include <fstream>
#include <sstream>
#include <utility>
#include <boost/multiprecision/cpp_int.hpp>

std::pair<boost::multiprecision::cpp_int, boost::multiprecision::cpp_int> read_file_data(const std::string& filename) {
    std::ifstream infile(filename);
    boost::multiprecision::cpp_int step = 1;
    boost::multiprecision::cpp_int sum_of_factors = 0;

    if (infile.is_open()) {
        std::string line;
        std::string last_line;
        while (std::getline(infile, line)) {
            last_line = line;
        }

        if (!last_line.empty()) {
            std::stringstream string_stream(last_line);
            std::string value;

            if (std::getline(string_stream, value, ',')) {
                step = boost::multiprecision::cpp_int(value);
            }

            if (std::getline(string_stream, value, ',')) {
                sum_of_factors = boost::multiprecision::cpp_int(value);
            }
        }
        infile.close();
    }

    return {step, sum_of_factors};
}