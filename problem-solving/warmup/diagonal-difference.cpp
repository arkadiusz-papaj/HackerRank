/*
 * Complete the 'diagonalDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

[[nodiscard]] auto diagonalDifference(vector<vector<int>> arr) -> int {
    auto size = arr.size();
    if (size == 0) return 0;
    assert(size == arr.at(0).size());
    
    auto sum = int{};
    
    for (std::size_t row = 0, col = 0; row < size; row++){
        sum += arr.at(row).at(col) - arr.at(row).at(size - 1 - col);
        col++;
    }
    
    return std::abs(sum);
}