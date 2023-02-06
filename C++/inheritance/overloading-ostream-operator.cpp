#include <iostream>
#include <string>
#include <utility>

class Person
{
public:
    Person(std::string first_name, std::string last_name) : first_name_{std::move(first_name)},
                                                            last_name_{std::move(last_name)} {}
    [[nodiscard]] auto get_first_name() const -> std::string const& {return first_name_;}
    [[nodiscard]] auto get_last_name() const -> std::string const& {return last_name_;}

friend auto operator<<(std::ostream& os, Person const& p) -> std::ostream& {
  os << "first_name=" << p.first_name_ << ",";
  os << "last_name=" << p.last_name_;
  return os;
};

private:
    std::string first_name_{};
    std::string last_name_{};
};

int main()
{
    auto first_name = std::string{};
    auto last_name = std::string{};
    auto event = std::string{};

    std::cin >> first_name >> last_name >> event;
    auto p = Person{first_name, last_name};
    std::cout << p << " " << event << '\n';
    return 0;
}