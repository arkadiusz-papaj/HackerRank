#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Student
{
   int age{};
   int standard{}; 
   string first_name{};
   string last_name{};

   friend auto operator<<(ostream& out, Student const& rhs) -> ostream&;
};

auto operator<<(ostream& out, Student const& rhs) -> ostream& {
    out << rhs.age << " " << rhs.first_name << " " << rhs.last_name << " " << rhs.standard;
    return out;
};

int main() {
    auto student = Student{};
    
    std::cin >> student.age >> student.first_name >> student.last_name >> student.standard;
    std::cout << student;
    
    return 0;
}