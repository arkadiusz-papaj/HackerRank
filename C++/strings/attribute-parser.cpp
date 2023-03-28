#include <iostream>
#include <unordered_map>
#include <string>
#include <string_view>
// 4 3
// <tag1 value = "HelloWorld">
// <tag2 name = "Name1">
// </tag2>
// </tag1>
// tag1.tag2~name
// tag1~name
// tag1~value
struct tag {
    std::string tag_id{};
    std::unordered_map<std::string, std::string> attributes{};
    std::unordered_map<std::string, tag> nested_tags{};

    [[nodiscard]] auto parse_query(std::string_view query) -> std::string_view {
        auto constexpr atribute_value = std::string_view{"Not found!"};

        if (*query.begin() == '~') {
            //fetch from attr
            if (auto attribute = attributes.find({query.begin() + 1, query.end()}); attribute != attributes.end()) {
                atribute_value = std::string_view{attribute->second};
            }
        }
        else {//some tags
        // fetch tag name
        auto tag_separator = query.find_first_of('.');
        if (tag_separator != std::string_view::npos) {
            auto tag_name = query.remove_prefix()
        }
        else {
            
        }
        // if present in nested tags -> strip its name and sent
        //  els                      -> return not found
        }

        return atribute_value;
    }
};

struct HRML_document {
    std::unordered_map<std::string, tag> tags{};
    [[nodiscard]] auto parse_query(std::string_view query) -> std::optional<std::string_view>;
};

// [[nodiscard]] auto parse_hrml_line(std::string_view line) -> std::optional<tag> {
//     auto parsed_tag = std::optional<tag>{}
//     if (line.at(2) == '/') 
// }

[[nodiscard]] auto HRML_document::parse_query(std::string_view query) -> std::optional<std::string_view> {
    auto tag_separator_pos = query.find_first_of('.');
    auto tag_attribute = query.find_first_of('~');


}

int main() {
    auto no_of_HRML_lines = unsigned{};
    auto no_of_queries = unsigned{};

    std::cin >> no_of_HRML_lines >> no_of_queries;


    return EXIT_SUCCESS;
}