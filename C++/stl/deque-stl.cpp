#include <iostream>
#include <deque>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cassert>

auto printKMax(std::vector<unsigned> const& container, unsigned window_size) -> void {
    assert(container.size() >= window_size);
    auto sliding_window = std::deque<unsigned>{container.begin(), container.begin() + window_size};
    auto max_values = std::vector<unsigned>{};
    max_values.reserve(container.size() - window_size + 1);

    auto window_max_value = *std::max_element(sliding_window.begin(), sliding_window.end());
    max_values.emplace_back(window_max_value);

    std::for_each(container.begin() + window_size,
                  container.end(),
                  [&](auto entering_window){
                    auto leaving_window = sliding_window.front();
                    sliding_window.pop_front();
                    sliding_window.push_back(entering_window);

                    if (leaving_window != window_max_value) {
                        if (entering_window > window_max_value) {
                            window_max_value = entering_window;
                        }
                    }
                    else {
                        if (entering_window >= window_max_value) {
                            window_max_value = entering_window;
                        }
                        else {
                            window_max_value = *std::max_element(sliding_window.begin(), sliding_window.end());
                        }
                    }

                    max_values.emplace_back(window_max_value);
                  });

 
    std::copy(max_values.begin(), max_values.end(), std::ostream_iterator<unsigned>(std::cout, " "));
    std::cout << '\n';
};

int main()
{
    auto vect = std::vector<unsigned>{};
    auto numer_of_tests = unsigned{};
    auto vector_size = unsigned{};
    auto window_size = unsigned{};

    std::cin >> numer_of_tests;
    
    for (auto i = unsigned{0}; i < numer_of_tests; i++) {
        std::cin >> vector_size >> window_size;
        vect.reserve(vector_size);
        std::copy_n(std::istream_iterator<unsigned>(std::cin),
                    vector_size,
                    std::back_inserter(vect));

        // std::copy(vect.begin(), vect.end(), std::ostream_iterator<unsigned>(std::cout, " "));
        printKMax(vect, window_size);
        vect.clear();
    }
    
    return 0;
}