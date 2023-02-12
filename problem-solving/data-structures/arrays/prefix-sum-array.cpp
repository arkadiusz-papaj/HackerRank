#include <vector>
#include <algorithm>

/*
 * Complete the 'arrayManipulation' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */

[[nodiscard]] auto arrayManipulation(int n, std::vector<std::vector<int>> queries) -> long {
    auto vect = std::vector<long>(n);
    
    std::for_each(queries.begin(), queries.end(), [&](auto const& row){
        //prefix sum array
        //from a to b add value x -> at a add x, at b+1 "revert" change (-x)
        auto a = row.at(0) - 1;
        auto b = row.at(1);
        auto x = row.at(2);
        vect.at(a) += x;
        //prevent out of bound
        if (b != n) vect.at(b) += (-x);
    });
    
    auto max = long{*vect.begin()};
    for (auto i = int{1}; i < vect.size(); i++) {
        vect.at(i) += vect.at(i - 1);
        max = std::max(max, vect.at(i));
    }
    
    return max;
}