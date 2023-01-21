/*
 * Complete the 'simpleArraySum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY ar as parameter.
 */

[[nodiscard]] auto simpleArraySum(vector<int> ar) -> int {
    return std::accumulate(ar.begin(), ar.end(), decltype(ar)::value_type(0));
}