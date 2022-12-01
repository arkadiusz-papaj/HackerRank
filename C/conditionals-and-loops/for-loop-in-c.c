#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char* toString(int number){
    switch(number){
        case 1: return "one";
        case 2: return "two";
        case 3: return "three";
        case 4: return "four";
        case 5: return "five";
        case 6: return "six";
        case 7: return "seven";
        case 8: return "eight";
        case 9: return "nine";
        default: return "greater than nine";
    }
}

int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	// Complete the code.
    for (int i = a; i <= b; i++){
        if (i <= 9) printf("%s\n", toString(i));
        else {
            (i % 2) ? printf("odd\n") : printf("even\n");
        }
    }
    return 0;
}