#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <numeric>


int main()
{
    auto grades = std::map<std::string, std::vector<unsigned>>{};
    
    auto query_type = unsigned{};
    auto grade = unsigned{};
    auto name = std::string{};
    auto numer_of_queries = unsigned{};
    std::cin >> numer_of_queries;
    
    enum class QueryType {
        AddMarks = 1,
        EraseMarks,
        Print
    };

    for (auto i = unsigned{0}; i < numer_of_queries; i++) {
        std::cin >> query_type >> name;
        
        switch(static_cast<QueryType>(query_type)){
            case QueryType::AddMarks:
                std::cin >> grade;
                if (auto [element, success] = grades.insert({name, {grade}}); success == false) {
                    grades[name].push_back(grade);
                }
            break;
            
            case QueryType::EraseMarks: grades.erase(name); break;
            
            case QueryType::Print:
                std::cout << (grades.find(name) == grades.end() ? 0 : std::accumulate(grades[name].begin(),
                                                                                      grades[name].end(),
                                                                                      unsigned{0})) << '\n';
            break;
        }
    }
    return 0;
}