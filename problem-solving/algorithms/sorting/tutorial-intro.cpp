#include <vector>

/*
 * Complete the 'introTutorial' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER V
 *  2. INTEGER_ARRAY arr
 */

[[nodiscard]] auto introTutorial(int V, std::vector<int> const& arr) -> int {
    auto index = int{0};

    while (arr.at(index) != V) {
        index++;
    }
    
    return index;
}