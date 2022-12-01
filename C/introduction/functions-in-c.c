#include <stdio.h>
/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/
#define max(a, b)({              \
            __auto_type _a = (a);\
            __auto_type _b = (b);\
            _a > _b ? _a : _b;   \
        })

int max_of_four(int a, int b, int c, int d){
    return max(max(max(a, b), c), d);
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}