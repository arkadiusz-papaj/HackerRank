#include <numeric>
#include <vector>
#include <iostream>

class Student
{
public:
    auto input() -> void;
    [[nodiscard]] auto calculateTotalScore() const -> int;
private:
    std::vector<int> scores{};
};

auto Student::input() -> void
{
    auto score = int{};
    constexpr auto no_of_scores = int{5};
    scores.reserve(no_of_scores);

    for (auto i = int{0}; i < no_of_scores; i++) {
        std::cin >> score;
        scores.emplace_back(score);
    }
};

auto Student::calculateTotalScore() const -> int
{
    return std::accumulate(scores.begin(), scores.end(), 0);
};