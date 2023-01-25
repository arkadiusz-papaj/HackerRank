#include <vector>
#include <numeric>

/*
 * Complete the 'aVeryBigSum' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER_ARRAY ar as parameter.
 */

[[nodiscard]] auto aVeryBigSum(std::vector<long> ar) -> long {
    return std::accumulate(ar.begin(), ar.end(), decltype(ar)::value_type(0));
}