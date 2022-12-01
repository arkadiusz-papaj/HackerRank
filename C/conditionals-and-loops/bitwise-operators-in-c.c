#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
    //Write your code here.
    unsigned int maximum_of_and = 0;
    unsigned int maximum_of_or  = 0;
    unsigned int maximum_of_xor = 0;
    
    for (int i = 1; i < n; i++){
        for (int j = i + 1; j <= n; j++){
            int and_operation = i & j;
            int or_operation = i | j;
            int xor_operation = i ^ j;

            if ((and_operation < k) && (and_operation > maximum_of_and)) maximum_of_and = and_operation;
            if ((or_operation < k) && (or_operation > maximum_of_or)) maximum_of_or = or_operation;
            if ((xor_operation < k) && (xor_operation > maximum_of_xor)) maximum_of_xor = xor_operation;
        }
    }
    
    printf("%d\n%d\n%d", maximum_of_and, maximum_of_or, maximum_of_xor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}