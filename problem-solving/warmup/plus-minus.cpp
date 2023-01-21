/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

auto plusMinus(vector<int> arr) -> void {
    const auto size = arr.size();
    auto positive_number = int{std::count_if(arr.begin(), arr.end(), [](int i){return i >= 1;})};
    auto negative_number = int{std::count_if(arr.begin(), arr.end(), [](int i){return i <= -1;})};
    auto zero_number = int{size - (positive_number + negative_number)};

    std::cout.setf(ios::fixed);
    std::cout.precision(6);
    
    std::cout << static_cast<double>(positive_number) / size << '\n';
    std::cout << static_cast<double>(negative_number) / size << '\n';
    std::cout << static_cast<double>(zero_number) / size << '\n';
}