#include <vector>
#include <algorithm>
#include <iostream>

/*
 * Complete the 'countApplesAndOranges' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER s
 *  2. INTEGER t
 *  3. INTEGER a
 *  4. INTEGER b
 *  5. INTEGER_ARRAY apples
 *  6. INTEGER_ARRAY oranges
 */

auto countApplesAndOranges(int start_point,
                           int end_point,
                           int apple_tree_location,
                           int orange_tree_location,
                           std::vector<int> apples,
                           std::vector<int> oranges) -> void {
    auto apple_positions = std::move(apples);
    std::for_each(apple_positions.begin(), apple_positions.end(), [=](auto & apple){
        apple += apple_tree_location;
    });

    auto oragne_positions = std::move(oranges);
    std::for_each(oragne_positions.begin(), oragne_positions.end(), [=](auto & orange){
        orange += orange_tree_location;
    });

    
    unsigned int apples_in_range = std::count_if(apple_positions.begin(),
                                                 apple_positions.end(),
                                                 [=](int fruit){return (fruit >= start_point) && (fruit <= end_point);});
                                                 
    unsigned int oranges_in_range = std::count_if(oragne_positions.begin(),
                                                  oragne_positions.end(),
                                                  [=](int fruit){return (fruit >= start_point) && (fruit <= end_point);});
    
    std::cout << apples_in_range << '\n' << oranges_in_range;
}