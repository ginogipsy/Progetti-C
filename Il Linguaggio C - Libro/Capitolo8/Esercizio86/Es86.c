#include <stdio.h>
#include <string.h>
#include <ctype.h>

void stringToLower(const char *sPtr);
void stringToUpper(const char *sPtr);

#define SIZE 100
int main(void)
{
    char sentence[SIZE];

    printf_s("%s\n","Insert a string max 100 chars:");
    fgets(sentence, SIZE, stdin);
    stringToUpper(sentence);
    stringToLower(sentence);
}

void stringToLower(const char *sPtr)
{
    int count = 0;
    while (sPtr[count] != '\0')
    {
        printf_s("%c",tolower(sPtr[count]));
        count++;
    }
    
}

void stringToUpper(const char *sPtr)
{
    int count = 0;
    while (sPtr[count] != '\0')
    {
        printf_s("%c",toupper(sPtr[count]));
        count++;
    }
    
}
