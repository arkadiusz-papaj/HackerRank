#include <iostream>

class Triangle {
	public:
		auto triangle() const -> void {
			std::cout << "I am a triangle\n";
		}
};

class Isosceles : public Triangle {
  	public:
  		auto isosceles() const -> void {
    		std::cout << "I am an isosceles triangle\n";
  		}
};

class Equilateral : public Isosceles {
    public:
        auto equilateral() const -> void {
           std::cout << "I am an equilateral triangle\n"; 
        }
};

int main()
{
    Equilateral eqr;
    eqr.equilateral();
    eqr.isosceles();
    eqr.triangle();
    return 0;
}