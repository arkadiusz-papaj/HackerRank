#include <iostream>
#include <set>

int main()
{
    auto s = std::set<int>{};
    auto numer_of_queries = unsigned{};
    std::cin >> numer_of_queries;
    
    enum class QueryType {
        Add = 1,
        Delete,
        Find
    };

    auto query_type = unsigned{};
    auto query_argument = decltype(s)::value_type{};
    
    for (auto i = unsigned{0}; i < numer_of_queries; i++) {
        std::cin >> query_type >> query_argument;
        
        switch (static_cast<QueryType>(query_type)) {
            case QueryType::Add : s.insert(query_argument); break;
            case QueryType::Delete : s.erase(query_argument); break;
            case QueryType::Find : std::cout << (s.find(query_argument) != s.end() ? "Yes\n" : "No\n"); break;
        }
    }
    
    return 0;
}