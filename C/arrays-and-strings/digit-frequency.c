#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    const size_t MAX_SIZE = 1000;
    const char ASCII_ZERO_CODE = 48;
    char string[MAX_SIZE];
    char numbers_frequencies[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    fgets(string, MAX_SIZE, stdin);
    
    for (size_t i = 0; string[i] != '\n'; i++){
        if (isdigit(string[i])) numbers_frequencies[string[i] - ASCII_ZERO_CODE]++;
    }
    
    for (size_t i = 0; i < 10; i++){
        printf("%d ", numbers_frequencies[i]);
    }
    
    return 0;
}