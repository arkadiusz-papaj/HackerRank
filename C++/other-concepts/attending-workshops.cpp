#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <iterator>
#include <utility>

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

struct Workshop
{
    unsigned start_time{};
    unsigned duration{};
    unsigned end_time{};
    
    bool operator<(Workshop const& w) const {
        return this->end_time < w.end_time;
    };
};

struct Available_Workshops {
    unsigned no_of_workshops_signed{};
    std::vector<Workshop> workshops{};
    
    explicit Available_Workshops(unsigned n) : no_of_workshops_signed{n} {
        workshops.reserve(no_of_workshops_signed);
    };
};

[[nodiscard]] auto initialize (std::vector<unsigned> const& start_times, std::vector<unsigned> const& duration, unsigned n) -> Available_Workshops {
    assert(start_times.size() == duration.size());
    Available_Workshops avail_workshop{n};
    
    // great place for ranges::view::zip... since C++23 :(
    for (auto i = unsigned{0}; i < n; i++) {
        avail_workshop.workshops.push_back({start_times[i], duration[i], start_times[i] + duration[i]});
    }
    
    std::sort(avail_workshop.workshops.begin(), avail_workshop.workshops.end());
    
    return avail_workshop;
};

[[nodiscard]] auto CalculateMaxWorkshops(Available_Workshops const& timeplan) -> unsigned {
    auto last_workshop_end_time = unsigned{};

    return std::count_if(timeplan.workshops.begin(),
                         timeplan.workshops.end(),
                         [&last_workshop_end_time](Workshop const& w){
                            if (w.start_time >= last_workshop_end_time){
                                last_workshop_end_time = w.end_time;
                                return true;
                            }
                            else return false;});
};

int main()
{
    auto no_of_workshops = unsigned{};
    std::cin >> no_of_workshops;

    auto start_time = std::vector<unsigned>{};
    start_time.reserve(no_of_workshops);
    auto duration = std::vector<unsigned>{};
    duration.reserve(no_of_workshops);

    std::copy_n(std::istream_iterator<unsigned>(std::cin), no_of_workshops, std::back_inserter(start_time));
    std::copy_n(std::istream_iterator<unsigned>(std::cin), no_of_workshops, std::back_inserter(duration));

    auto avail_workshops = Available_Workshops{no_of_workshops};
    avail_workshops = initialize(start_time, duration, no_of_workshops);
    std::cout << CalculateMaxWorkshops(avail_workshops) << '\n';

    return 0;
}