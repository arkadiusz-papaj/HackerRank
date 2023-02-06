#include <iostream>
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box
{
public:
    Box() = default;
    Box(int length, int breadth, int height) : l{length}, b{breadth}, h{height}{};
    Box(Box const& other) = default;
    Box(Box && other) = default;
    Box& operator=(Box const& other) = default;
    Box& operator=(Box && other) = default;
    ~Box() = default;
    
    [[nodiscard]] constexpr auto getLength() const noexcept -> int {return this->l;};
    [[nodiscard]] constexpr auto getBreadth() const noexcept -> int {return this->b;};
    [[nodiscard]] constexpr auto getHeight() const noexcept -> int {return this->h;};
    [[nodiscard]] constexpr auto CalculateVolume() const noexcept -> long long {return static_cast<long long>(l)*b*h;};

    constexpr auto operator<(Box const& other) const noexcept -> bool {
        return ((l < other.l) ||
                (b < other.b && l == other.l) ||
                (h < other.h && b == other.b && l == other.l));
    };

    friend auto operator<<(std::ostream& out, Box const& box) -> std::ostream& {
        return out << box.l << " " << box.b << " " << box.h;
    };
        
private:
    int l{0};
    int b{0};
    int h{0}; 
};