#include <iostream>
#include <iomanip> 

int main()
{
	auto tests = unsigned{};
    auto A = double{};
    auto B = double{};
    auto C = double{};

    std::cin >> tests;
	std::cout << std::setiosflags(std::ios::uppercase);
	std::cout << std::setw(0xf) << std::internal;

	while (tests--) {
		std::cin >> A >> B >> C;

		std::cout << std::hex << std::left << std::nouppercase << std::showbase;
        std::cout << static_cast<long long>(A) << '\n';
        
        std::cout << std::dec << std::right << std::setw(15) << std::setfill('_') << std::setprecision(2) << std::fixed << std::showpos;
        std::cout << B << '\n';
        
        std::cout << std::scientific << std::uppercase << std::setw(15);
        std::cout << std::setprecision(9) << std::fixed << std::scientific << std::noshowpos;
        std::cout << C << '\n';
	}

	return 0;
}