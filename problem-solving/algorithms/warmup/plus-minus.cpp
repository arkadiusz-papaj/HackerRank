#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>


/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

auto plusMinus(std::vector<int> arr) -> void {
    const auto size = arr.size();
    auto positive_number = std::size_t{std::count_if(arr.begin(), arr.end(), [](int i){return i >= 1;})};
    auto negative_number = std::size_t{std::count_if(arr.begin(), arr.end(), [](int i){return i <= -1;})};
    auto zero_number = std::size_t{size - (positive_number + negative_number)};

    std::cout.setf(std::ios::fixed);
    std::cout.precision(6);
    
    std::cout << static_cast<double>(positive_number) / size << '\n';
    std::cout << static_cast<double>(negative_number) / size << '\n';
    std::cout << static_cast<double>(zero_number) / size << '\n';
}