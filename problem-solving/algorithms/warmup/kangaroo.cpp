#include <string>
#include <cmath>

[[nodiscard]] auto kangaroo(int first_kangaroo_position, int first_kangaroo_speed,
                            int second_kangaroo_position, int second_kangaroo_speed) -> std::string {
    // back kangaroo must be faster
    if (((first_kangaroo_position < second_kangaroo_position) && (first_kangaroo_speed <= second_kangaroo_speed)) ||
        ((second_kangaroo_position < first_kangaroo_position) && (second_kangaroo_speed <= first_kangaroo_speed))) {
            return "NO";
        }
    
    /*do{
        first_position += v1;
        second_position += v2;
    }while(first_position < second_position);
    
    return (first_position == second_position) ? "YES" : "NO";*/
    
    // second solution ax + b = cx + d
    //
    // speed1*times + start1 = speed2*times + start2  | - start1
    // speed1*times  = speed2*times + start2 - start1 | - speed2*times
    // speed1*times - speed2*times = start2 - start1
    // times*(speed1 - speed2) = start2 - start1
    // times = (start2 - start1) / (speed1 - speed2)
    
    auto jump_times = static_cast<float>(second_kangaroo_position - first_kangaroo_position) / static_cast<float>(first_kangaroo_speed - second_kangaroo_speed);
    // jump_times must be integer otherwise one kangaroo on the ground and second one mid air
    return (jump_times == std::floor(jump_times) && jump_times >= 0) ? "YES" : "NO";
}