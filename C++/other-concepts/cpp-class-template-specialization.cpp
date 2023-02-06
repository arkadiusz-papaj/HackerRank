#include <iostream>

enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

template<>
struct Traits<Fruit>{
    static std::string name(int index){
        switch(index)
        {
            case static_cast<int>(Fruit::apple): return "apple";
            case static_cast<int>(Fruit::orange): return "orange";
            case static_cast<int>(Fruit::pear): return "pear";
            default: return "unknown";
        }
    }  
};

template<>
struct Traits<Color>{
    static std::string name(int index){
        switch(index)
        {
            case static_cast<int>(Color::red): return "red";
            case static_cast<int>(Color::green): return "green";
            case static_cast<int>(Color::orange): return "orange";
            default: return "unknown";
        }
    }  
};


int main()
{
	auto no_of_tests = unsigned{};
    std::cin >> no_of_tests;

    for (auto i = unsigned{0}; i < no_of_tests; no_of_tests++) {
        auto index1 = int{};
        auto index2 = int{};
        std::cin >> index1;
        std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
