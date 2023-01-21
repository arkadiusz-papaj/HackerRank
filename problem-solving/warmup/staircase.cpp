/*
 * Complete the 'staircase' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

auto staircase(int n) -> void {
    for (int i = 1; i <= n; ++i){
        std::cout << string(n - i, ' ') << string(i, '#') << '\n';
    }  
}