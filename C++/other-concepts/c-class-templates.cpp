#include <iostream>
#include <utility>
#include <string>

template<typename T>
class AddElements {
    public:
        template<typename ... Args>
        [[nodiscard]] constexpr auto add(Args ... elem) const {return (elem + ...) + class_value;};

        constexpr AddElements(T elem) : class_value{elem}{};
    private:
        T class_value;
};

template <>
class AddElements <std::string> {
    public:
        [[nodiscard]] std::string concatenate(std::string elem){
            return class_value.append(std::move(elem));
        };
        AddElements() = default;
        AddElements(std::string elem) : class_value{std::move(elem)}{};
        AddElements(AddElements const& other) = default;
        AddElements(AddElements && other) noexcept : class_value{std::move(other.class_value)} {other.class_value = std::string();};
        AddElements& operator=(AddElements const& other) = default;
        AddElements& operator=(AddElements && other) noexcept {
            if (this == &other) return *this;
            
            class_value = std::move(other.class_value);
            other.class_value = std::string();
            return *this;
        };
        virtual ~AddElements() noexcept = default;
    private:
        std::string class_value{};
};

template <typename T>
[[nodiscard]] auto testCase(std::istream & input) {
    auto arg1 = T{};
    auto arg2 = T{};
    input >> arg1 >> arg2;

    AddElements<T> testObj{arg1};
    return testObj.add(arg2);
};

template <>
[[nodiscard]] auto testCase<std::string>(std::istream & input) {
    auto arg1 = std::string{};
    auto arg2 = std::string{};
    input >> arg1 >> arg2;

    AddElements<std::string> testObj{arg1};
    return testObj.concatenate(arg2);
};

int main ()
{
    //for some reasons next two lines are necessary to pass C++14 and later...
    //HK servers are slow as fuck
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    auto test_type = std::string{};
    auto no_of_tests = unsigned{};
    std::cin >> no_of_tests;

    for (auto i = unsigned{0}; i < no_of_tests; i++) {
        std::cin >> test_type;
        if (test_type == "float") {std::cout << testCase<float>(std::cin) << '\n';}
        else if (test_type == "int") {std::cout << testCase<int>(std::cin) << '\n';}
        else if (test_type == "string") {std::cout << testCase<std::string>(std::cin) << '\n';}
    }
    return 0;
}