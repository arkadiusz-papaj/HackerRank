#include <vector>
#include <iostream>

int main()
{
    auto vect = std::vector<int>{};
    auto size = std::size_t{};
    auto elem = int{};
    auto position = int{};
    auto start = int{};
    auto end = int{};

    std::cin >> size;
    vect.reserve(size);

    for (auto i = std::size_t{0}; i < size; i++) {
        std::cin >> elem;
        vect.emplace_back(elem);
    }
    
    std::cin >> position;
    vect.erase(vect.begin() + position - 1);

    std::cin >> start >> end;
    vect.erase(vect.begin() + start - 1, vect.begin() + end - 1);
    
    std::cout << vect.size() << '\n';
    for (auto const& elem : vect) {
        std::cout << elem << " ";
    }

    return 0;
}