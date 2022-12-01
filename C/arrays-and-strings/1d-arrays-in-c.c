#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    size_t array_size = 0;
    scanf("%zu\n", &array_size);
    
    unsigned long* arr = malloc(array_size * sizeof(unsigned long));
    if (arr == NULL) return 1;
    
    for (size_t i = 0; i < array_size; i++){
        scanf("%zu", &arr[i]);
    }
    
    unsigned long sum = 0;
    for (size_t i = 0; i < array_size; i++){
        sum += arr[i];
    }
    
    printf("%zu", sum);
    
    free(arr);
    
    return 0;
}