#include <iostream>

class Rectangle {
    public:
        virtual auto display() const -> void {std::cout << width << " " << height << '\n';};
        auto read_input() -> void {std::cin >> width >> height;};
        constexpr auto get_width() const -> unsigned {return width;};
        constexpr auto get_height() const -> unsigned {return height;};
        
        Rectangle() = default;
        Rectangle(unsigned width, unsigned height) : width{width}, height{height}{};
        Rectangle(Rectangle const& other) = default;
        Rectangle(Rectangle&& other) = default;
        Rectangle& operator=(const Rectangle& other) = default;
        Rectangle& operator=(Rectangle&& other) = default;
        virtual ~Rectangle() = default;

    private:
        unsigned width{};
        unsigned height{};
};

class RectangleArea : public Rectangle {
    public:
        auto display() const -> void override {std::cout << get_width() * get_height() << '\n';};
};

int main()
{
    RectangleArea r_area;
    r_area.read_input();
    r_area.Rectangle::display();
    r_area.display();
    
    return 0;
}