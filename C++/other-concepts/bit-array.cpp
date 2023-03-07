#include <iostream>

int main() {
    auto N = std::size_t{};
    auto S = std::size_t{};
    auto P = std::size_t{};
    auto Q = std::size_t{};
    auto max_size = std::size_t{1UL << 31};
    auto no_of_unique = std::size_t{};
    
    std::cin >> N >> S >> P >> Q;
    
    auto current = S % max_size;
    no_of_unique++;
    auto prev = current;
    
    for (auto i = std::size_t{1}; i < N; i++) {
        current = (prev * P + Q) % max_size;
        if (current != prev) {
            no_of_unique++;
        }
        else {
           break;
        }
        prev = current;
    }
    
    std::cout << no_of_unique;
    
    return 0;
}