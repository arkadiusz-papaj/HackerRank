#include <iostream>
#include <string>
#include <string_view>
#include <charconv>

class Complex
{
public:
    void input(std::string_view complex_string) {
        auto plus_position = complex_string.find_first_of('+');
        auto result = int{};
        if (auto [ptr, erc] = std::from_chars(complex_string.data(),
                                              complex_string.data() + plus_position,
                                              result); erc == std::errc()) {
            real = result;
        }

        if (auto [ptr, erc] = std::from_chars(complex_string.data() + plus_position + 2,
                                              complex_string.data() + complex_string.size(),
                                              result); erc == std::errc()) {
            imaginary = result;
        }
    };

    Complex operator+(Complex const& other) const {
        Complex sum;
        sum.real = real + other.real;
        sum.imaginary =imaginary + other.imaginary;
        return sum;
    };

    friend std::ostream & operator<<(std::ostream & os, Complex const& other) {
        return os << other.real << "+i" << other.imaginary;
    };

private:
    int real{};
    int imaginary{};
};

int main()
{
    auto first = Complex{};
    auto second = Complex{};
    auto s1 = std::string{};
    auto s2 = std::string{};
    std::cin >> s1;
    std::cin >> s2;
    first.input(s1);
    second.input(s2);
    Complex result = first + second;
    std::cout << result << '\n';

    return 0;
}