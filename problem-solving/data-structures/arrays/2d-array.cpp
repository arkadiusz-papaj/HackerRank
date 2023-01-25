#include <vector>
#include <climits>

/*
 * Complete the 'hourglassSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

[[nodiscard]] auto hourglassSum(const std::vector<std::vector<int>>& arr) -> int {
    auto sum = int{INT_MIN};
    auto sub_sum = int{0};
    auto offset = std::size_t{3};

    for (std::size_t i = 0; i <= offset; ++i){
        for (std::size_t j = 0; j <= offset; ++j){
            sub_sum = arr.at(i).at(j) +
                      arr.at(i).at(j + 1) +
                      arr.at(i).at(j + 2) +
                      arr.at(i + 1).at(j + 1) +
                      arr.at(i + 2).at(j) +
                      arr.at(i + 2).at(j + 1) +
                      arr.at(i + 2).at(j + 2);
            if (sub_sum > sum) sum = sub_sum;
        }
    }
    return sum;
}