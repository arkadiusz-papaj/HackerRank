#include <vector>
#include <map>
#include <numeric>
#include <algorithm>

[[nodiscard]] auto sockMerchant(int n, std::vector<int> sock_basket) -> int {
    auto socks_histogram = std::map<decltype(sock_basket)::value_type, int>{};
    
    std::for_each(sock_basket.begin(), sock_basket.end(), [&](auto const& sock){
        if (auto [sock_inserted, result] = socks_histogram.insert({sock, 1}); result == false) {
            socks_histogram[sock]++;
        }
    });
    
    return std::accumulate(socks_histogram.begin(), socks_histogram.end(), 0,
                           [](int sum, auto const& sock_type){
                               return sum + (sock_type.second / 2);
                           });

}