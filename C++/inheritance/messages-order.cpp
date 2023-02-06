#include <string>
#include <utility>

class Message
{
public: 
    Message(std::string msg = "") : my_id{getMyID()}, msg{std::move(msg)}{};
    
    auto get_text() const noexcept -> std::string const& {return this->msg;};
    
    constexpr auto operator<(Message const& other) const noexcept -> bool {
        return my_id < other.my_id;
    };

private:
    [[nodiscard]] auto getMyID() noexcept -> unsigned {
        static unsigned ID = 0;
        return ++ID;
    };
    unsigned my_id{};
    std::string msg{};
};

class MessageFactory {
public:
    Message create_message(std::string const& text) {return Message(text);};
};