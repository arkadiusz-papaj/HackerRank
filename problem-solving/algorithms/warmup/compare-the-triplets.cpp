#include <cassert>
#include <vector>

/*
 * Complete the 'compareTriplets' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

[[nodiscard]] auto compareTriplets(std::vector<int> a, std::vector<int> b) -> std::vector<int> {
    assert(a.size() == b.size());

    auto points = std::vector<int>{0, 0};
    
    for (size_t i = 0; i < a.size(); i++){
        if (a.at(i) > b.at(i)) ++(points.at(0));
        else if (a.at(i) < b.at(i)) ++(points.at(1));
    }
    
    return points;
}