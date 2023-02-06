#include <exception>
#include <string>

class BadLengthException : public std::exception
{
public:
    BadLengthException() = default;
    BadLengthException(int n) : n{n} {};
    BadLengthException(BadLengthException const& except) = default;
    BadLengthException(BadLengthException && except) = default;
    BadLengthException& operator=(BadLengthException const& except) = default;
    BadLengthException& operator=(BadLengthException && except) = default;
    ~BadLengthException() override = default;
        
    auto what() -> char const* {
        return std::to_string(n).c_str();
    }
    
private:
    int n{};
};