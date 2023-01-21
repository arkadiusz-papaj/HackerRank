/*
 * Complete the 'birthdayCakeCandles' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY candles as parameter.
 */

[[nodiscard]] auto birthdayCakeCandles(vector<int> candles) -> int {
    const int highest_candle = *std::max_element(candles.begin(), candles.end());
    return std::count_if(candles.begin(), candles.end(), [&](int i){return i == highest_candle;});
}