#include <stdio.h>
#include <string.h>

#define SIZE 90

int main(void)
{
    char sentences[2][SIZE];
    int number;
    printf_s("%s\n","Insert 2 sentences and the numbers of characters to compare,I say if 1st is bigger, smaller or equals than 2nd");
    for(size_t i=0;i<2;i++)
    {
        printf_s("%s%d%s","Insert ",i+1," sentence: ");
        fgets(sentences[i], SIZE, stdin);
    }
    printf_s("\n%s","Insert numbers of characters to compare: ");
    scanf("%d", &number);

    int value = strncmp(sentences[0], sentences[1], number);
    if(value < 0)
    {
        printf_s("\n%s%s%s",sentences[0]," is smaller than ",sentences[1]);
    }
    if(value == 0)
    {
        printf_s("\n%s%s%s",sentences[0]," is equals than ",sentences[1]);
    }
    if(value > 0)
    {
        printf_s("\n%s%s%s",sentences[0]," is bigger than ",sentences[1]);
    }
}
