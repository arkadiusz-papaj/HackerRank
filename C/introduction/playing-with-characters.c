#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    char c;
    const size_t MAX_SIZE = 100;
    char word[MAX_SIZE];
    char sentence[MAX_SIZE];
    
    scanf("%[^\n]%*c", &c);
    fgets(word, MAX_SIZE, stdin);
    fgets(sentence, MAX_SIZE, stdin);
    
    printf("%c\n", c);
    printf("%s", word);
    printf("%s", sentence);
    return 0;
}