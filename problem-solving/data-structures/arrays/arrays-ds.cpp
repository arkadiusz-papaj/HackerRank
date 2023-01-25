#include <vector>
#include <algorithm>

/*
 * Complete the 'reverseArray' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

[[nodiscard]] auto reverseArray(std::vector<int> arr) -> std::vector<int> {
    std::reverse(arr.begin(), arr.end());
    return arr;
}