#include <iostream>
#include <sstream>
using namespace std;

class Student
{
public:
    constexpr auto set_age(int age) noexcept -> void {this->age = age;};
    constexpr auto set_standard(int standard) noexcept -> void {this->standard = standard;};
    auto set_first_name(string name) noexcept -> void {this->first_name = std::move(name);};
    auto set_last_name(string name) noexcept -> void {this->last_name = std::move(name);};

    [[nodiscard]] constexpr auto get_age() const noexcept -> int {return age;};
    [[nodiscard]] constexpr auto get_standard() const noexcept -> int {return standard;};
    [[nodiscard]] auto get_first_name() const noexcept -> std::string {return first_name;};
    [[nodiscard]] auto get_last_name() const noexcept -> std::string {return last_name;};

    auto to_string() const noexcept -> std::string 
    {
        stringstream stream;
        stream << age << "," << first_name << "," << last_name << "," << standard;
        return stream.str();
    };
 
private:
    int age{};
    int standard{}; 
    std::string first_name{};
    std::string last_name{};
};

int main()
{
    auto age = int{};
    auto standard = int{};
    auto first_name = std::string{};
    auto last_name = std::string();
    
    std::cin >> age >> first_name >> last_name >> standard;
    
    auto student = Student{};
    student.set_age(age);
    student.set_standard(standard);
    student.set_first_name(first_name);
    student.set_last_name(last_name);
    
    std::cout << student.get_age() << "\n";
    std::cout << student.get_last_name() << ", " << student.get_first_name() << "\n";
    std::cout << student.get_standard() << "\n";
    std::cout << "\n";
    std::cout << student.to_string();
    
    return 0;
}