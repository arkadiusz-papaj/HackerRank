#include <iostream>
#include <vector>
#include <memory>
#include <numeric>

class HotelRoom
{
public:
    HotelRoom(int bedrooms, int bathrooms) : bedrooms_{bedrooms}, bathrooms_{bathrooms} {};
    HotelRoom() = default;
    HotelRoom(HotelRoom const& other) = default;
    HotelRoom(HotelRoom && other) = default;
    HotelRoom& operator=(HotelRoom const& other) = default;
    HotelRoom& operator=(HotelRoom && other) = default;
    virtual ~HotelRoom() = default;
    
    [[nodiscard]] virtual auto get_price() const -> int {
        return price_per_bedroom * bedrooms_ +
               price_per_bathroom * bathrooms_;
    }

private:
    int bedrooms_{};
    int bathrooms_{};
    const int price_per_bedroom{50};
    const int price_per_bathroom{100};
};

class HotelApartment : public HotelRoom
{
public:
    HotelApartment(int bedrooms, int bathrooms) : HotelRoom{bedrooms, bathrooms} {}
    HotelApartment() = default;
    HotelApartment(HotelApartment const& other) = default;
    HotelApartment(HotelApartment && other) = default;
    HotelApartment& operator=(HotelApartment const& other) = default;
    HotelApartment& operator=(HotelApartment && other) = default;
    virtual ~HotelApartment() = default;
    
    [[nodiscard]] auto get_price() const -> int override {
        return HotelRoom::get_price() + apartament_extra_price;
    }
private:
    const int apartament_extra_price{100};
};

int main()
{
    auto no_of_rooms = unsigned{};
    auto no_of_bedrooms = unsigned{};
    auto no_of_bathrooms = unsigned{};
    auto room_type = std::string{};

    std::cin >> no_of_rooms;
    std::vector<std::unique_ptr<HotelRoom>> rooms;
    rooms.reserve(no_of_rooms);

    for (auto i = unsigned{0}; i < no_of_rooms; ++i) {
        std::cin >> room_type >> no_of_bedrooms >> no_of_bathrooms;
        if (room_type == "standard") {
            rooms.emplace_back(std::make_unique<HotelRoom>(no_of_bedrooms, no_of_bathrooms));
        } else {
            rooms.emplace_back(std::make_unique<HotelApartment>(no_of_bedrooms, no_of_bathrooms));
        }
    }

    std::cout << std::accumulate(rooms.begin(), rooms.end(), 0, [](int sum, std::unique_ptr<HotelRoom> const& room){return sum + room->get_price();}) << '\n';

    return 0;
}