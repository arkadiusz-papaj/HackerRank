#include <vector>

/*
 * Complete the 'rotateLeft' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER d
 *  2. INTEGER_ARRAY arr
 */

[[nodiscard]] auto rotateLeft(int d, std::vector<int> arr) -> std::vector<int> {
    if ((arr.size() < 2) or (d == 0)) return arr;
    
    auto to_left = std::vector<int>{arr.begin(), arr.begin() + d};
    arr.erase(arr.begin(), arr.begin() + d);
    arr.insert(arr.end(),
               std::make_move_iterator(to_left.begin()),
               std::make_move_iterator(to_left.end()));
    
    return arr;
}