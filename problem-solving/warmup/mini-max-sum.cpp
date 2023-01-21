/*
 * Complete the 'miniMaxSum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

auto miniMaxSum(vector<int> arr) -> void {
    std::sort(arr.begin(), arr.end());
    // only to not execute accumulate twice on large vector
    auto sum = std::accumulate(arr.begin(), arr.end(), 0LL);
    
    std::cout << sum - arr.back() << " "
              << sum - arr.front() << '\n';
}