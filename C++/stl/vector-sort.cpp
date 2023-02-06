#include <vector>
#include <iostream>
#include <algorithm>
#include <execution>

int main()
{
    auto vect = std::vector<int>{};
    auto size = std::size_t{};
    auto value = int{};

    std::cin >> size;
    vect.reserve(size);
    
    for (auto i = std::size_t{0}; i < size; i++) {
        std::cin >> value;
        vect.emplace_back(value);
    }
    
    std::sort(std::execution::par, vect.begin(), vect.end());
    
    std::for_each(vect.begin(), vect.end(), [](auto val = int{}){
        std::cout << val << " ";
    });

    return 0;
}