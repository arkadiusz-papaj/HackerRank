#include <vector>
#include <numeric>
#include <iostream>

auto bonAppetit(std::vector<int> bill, int k, int b) -> void {
   auto anna_bill = (std::accumulate(bill.begin(),
                                     bill.end(),
                                     decltype(bill)::value_type(0)) - bill.at(k)) / 2;
   auto difference = b - anna_bill;
   (difference == 0) ? std::cout << "Bon Appetit" : std::cout << difference;
}