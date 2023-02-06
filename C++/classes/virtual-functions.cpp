#include <iostream>
#include <vector>
#include <numeric>

class Person
{
public:
    virtual auto putdata(std::ostream& out) -> void = 0;
    virtual auto getdata(std::istream& in) -> void = 0;
    Person() = default;
    Person(int age, std::string name, unsigned int id) : age{age}, name{std::move(name)}, my_id{id} {};
    Person(Person const& person) = default;
    Person(Person && person) = default;
    Person& operator=(Person const& rhs) = default;
    Person& operator=(Person&& rhs) = default;
    virtual ~Person() = default;
protected:
    int age{};
    std::string name{};
    const unsigned my_id{};
};

class Professor : public Person
{
public:
    auto putdata(std::ostream& out) -> void override {
        out << name << " " << age << " " << publications << " " << my_id;
    };
    auto getdata(std::istream& in) -> void override {
        in >> name >> age >> publications;
    };
    Professor() : Person(0, "", getMyID()){};
    Professor(Professor const& prof) = default;
    Professor(Professor && prof) = default;
    Professor& operator=(Professor const& rhs) = default;
    Professor& operator=(Professor && rhs) = default;
    virtual ~Professor() = default;

private:
    int publications{};
    [[nodiscard]] auto getMyID() noexcept -> unsigned {
        static unsigned ID = 0;
        return ++ID;
    };
};

class Student : public Person
{
public:
    auto putdata(std::ostream& out) -> void override {
        out << name << " " << age << " " << std::accumulate(marks.begin(), marks.end(), 0) << " " <<  my_id;
    };
    auto getdata(std::istream& in) -> void override;
    Student() : Person(0, "", getMyID()){marks.reserve(maxNumberOfMarks);};
    Student(Student const& student) = default;
    Student(Student&& student) = default;
    Student& operator=(Student const& rhs) = default;
    Student& operator=(Student && rhs) = default;
    virtual ~Student() = default;

private:
    std::vector<int> marks{};
    [[nodiscard]] auto getMyID() const noexcept -> unsigned {
        static unsigned ID = 0;
        return ++ID;
    };
    static constexpr uint8_t maxNumberOfMarks{6};
};

auto Student::getdata(std::istream& in) -> void {
    in >> name >> age;
    auto mark = int{};

    for (auto i = int{0}; i < maxNumberOfMarks; i++) {
        in >> mark;
        marks.emplace_back(mark);
    }
};