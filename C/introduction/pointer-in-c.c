#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function
    unsigned int sum = (*a) + (*b);
    int difference = (*a) - (*b);
    const int MASK = difference >> 31;
    *a = sum;
    *b = (difference + MASK) ^ MASK;   
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}