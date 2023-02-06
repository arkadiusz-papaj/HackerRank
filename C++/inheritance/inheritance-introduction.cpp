#include <iostream>

class Triangle {
    public:
    	auto triangle() const -> void {
     		std::cout << "I am a triangle\n";
    	};
};

class Isosceles : public Triangle {
    public:
    	auto isosceles() const -> void {
    		std::cout << "I am an isosceles triangle\n";
    	};
  		auto description() const -> void {
            std::cout << "In an isosceles triangle two sides are equal\n";
        };
};

int main()
{
    Isosceles isc;
    isc.isosceles();
  	isc.description();
    isc.triangle();
    return 0;
}