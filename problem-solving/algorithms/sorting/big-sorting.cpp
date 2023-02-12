#include <vector>
#include <string>
#include <algorithm>

[[nodiscard]] auto bigSorting(std::vector<std::string> unsorted) noexcept -> std::vector<std::string>{
    std::sort(unsorted.begin(), unsorted.end(), [](std::string const& first, std::string const& second) {
        return (first.size() == second.size()) ? first < second : first.size() < second.size();
    });

    return unsorted;
}