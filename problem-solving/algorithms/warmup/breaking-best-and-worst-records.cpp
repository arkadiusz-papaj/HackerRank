#include <vector>
#include <algorithm>

/*
 * Complete the 'breakingRecords' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY scores as parameter.
 */

[[nodiscard]] auto breakingRecords(std::vector<int> scores) -> std::vector<int> {
    auto records = std::vector<int>(2, 0);
    if (scores.size() < 2) {
        return records;
    }
    
    auto min_score = scores.at(0);
    auto max_score = scores.at(0);

    std::for_each(scores.begin(), scores.end(), [&](int score){
        if (score < min_score) {
            min_score = score;
            records.at(1)++;
        }
        else if (score > max_score) {
            max_score = score;
            records.at(0)++;
        }});
    
    return records;
}