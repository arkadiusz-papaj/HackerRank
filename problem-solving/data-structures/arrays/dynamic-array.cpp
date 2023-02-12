#include <vector>
#include <algorithm>

/*
 * Complete the 'dynamicArray' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */

[[nodiscard]] auto dynamicArray(int n, std::vector<std::vector<int>> queries) -> std::vector<int> {
    auto answers_for_type_2_queries = std::vector<int>{};
    answers_for_type_2_queries.reserve(queries.size() - 1);
    auto arr = std::vector<std::vector<int>>(n);
    auto last_answer = int{0};

    enum class QueryType {
        First = 1,
        Second
    };

    std::for_each(queries.begin(), queries.end(), [&](auto const& row){
        auto q_type = row.at(0);
        auto x = row.at(1);
        auto y = row.at(2);
        auto idx = int{(x ^ last_answer) % n};

        switch (static_cast<QueryType>(q_type)) {
            case QueryType::First :
                arr.at(idx).push_back(y);
            break;

            case QueryType::Second :
                last_answer = arr.at(idx).at(y % arr.at(idx).size());
                answers_for_type_2_queries.push_back(last_answer);
            break;
        }
    });

    return answers_for_type_2_queries;
}