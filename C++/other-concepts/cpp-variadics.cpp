#include <cstddef>

//reversed_binary_value<0,0,1>() should return 4
template <bool... digits>
[[nodiscard]] constexpr auto reversed_binary_value() -> int {
    auto value = int{0};
    auto bit_index = std::size_t{0};

    for (auto const bit : {digits...}) {
        value |= (static_cast<int>(bit) << bit_index);
        bit_index++;
    }

    return value;
};