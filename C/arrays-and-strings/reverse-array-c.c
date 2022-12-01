#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    scanf("%d", &num);
    int* arr = (int*) malloc(num * sizeof(int));
    if (arr == NULL) return 1;
    
    for(int i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }

    /* Write the logic to reverse the array. */
    for(int i = 0; i < num / 2; i++){
        int tmp = arr[i];
        arr[i] = arr[num - i - 1];
        arr[num - i - 1] = tmp;
    }

    for(int i = 0; i < num; i++){
        printf("%d ", *(arr + i));
    }
    
    free(arr);
    return 0;
}