#include <vector>
#include <string>
#include <algorithm>

/*
 * Complete the 'matchingStrings' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY stringList
 *  2. STRING_ARRAY queries
 */

[[nodiscard]] auto matchingStrings(std::vector<std::string> stringList,
                                   std::vector<std::string> queries) -> std::vector<int> {
    auto results = std::vector<int>{};
    results.reserve(queries.size());

    std::for_each(queries.begin(), queries.end(), [&](const decltype(queries)::value_type& query){
        results.push_back(static_cast<int>(std::count(stringList.begin(), stringList.end(), query)));
    });

    return results;
}