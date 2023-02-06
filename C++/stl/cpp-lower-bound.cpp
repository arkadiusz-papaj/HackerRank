#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    auto vect = std::vector<unsigned>{};
    auto size = std::size_t{};
    auto elem = decltype(vect)::value_type{};

    std::cin >> size;
    vect.reserve(size);
    
    for (auto i = std::size_t{0}; i < size; i++) {
        std::cin >> elem;
        vect.emplace_back(elem);
    }
    
    auto noOfQueries = unsigned{};
    std::cin >> noOfQueries;
    
    auto iter = decltype(vect)::iterator{};
    auto searched = unsigned{};
    auto position = std::size_t{};

    for (auto i = decltype(noOfQueries){0}; i < noOfQueries; i++) {
        std::cin >> searched;
        iter = lower_bound(vect.begin(), vect.end(), searched);
        
        position = iter - vect.begin() + 1;
        
        std::cout << (*iter == searched ? "Yes " : "No ");
        std::cout << position << '\n';
    }
    
    return 0;
}