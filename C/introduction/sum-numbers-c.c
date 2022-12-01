#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	unsigned int a = 0;
    unsigned int b = 0;
    float c = 0.0;
    float d = 0.0;
    
    scanf("%u %u", &a, &b);
    scanf("%f %f", &c, &d);
    
    printf("%d %d", a+b, a-b);
    printf("\n");
    printf("%.1f %.1f", c+d, c-d);
    
    return 0;
}