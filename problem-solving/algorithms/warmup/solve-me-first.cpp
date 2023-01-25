#include <iostream>

[[nodiscard]] constexpr auto solveMeFirst(int a, int b) -> int {
    // Hint: Type return a+b; below
    return a+b;
}

int main() {
    int num1 {};
    int num2 {};
    std::cin >> num1 >> num2;
    std::cout << solveMeFirst(num1,num2);
    return 0;
}