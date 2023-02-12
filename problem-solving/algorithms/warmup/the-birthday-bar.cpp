#include <vector>
#include <deque>
#include <numeric>
#include <algorithm>

/*
 * Complete the 'birthday' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY s
 *  2. INTEGER d
 *  3. INTEGER m
 */

[[nodiscard]] auto birthday(std::vector<int> s, int d, int m) -> int {
    auto sum = d;
    auto length = m;
    auto answer = int{};
    auto sliding_window = std::deque<int>{s.begin(), s.begin() + length};
    if (std::accumulate(sliding_window.begin(), sliding_window.end(), 0) == sum) {
        answer++;
    }
    
    std::for_each (s.begin() + length, s.end(), [&](auto piece){
        sliding_window.pop_front();
        sliding_window.push_back(piece);
        if (std::accumulate(sliding_window.begin(), sliding_window.end(), 0) == sum) {
            answer++;
        }
    });

    return answer;
}