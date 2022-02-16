#include <stdio.h>
#include <string.h>
#include <time.h>

#define SIZE 90

void printLatinWord(const char *sentence);

int main(void)
{
    char sentence[SIZE] = "";
    printf_s("%s\n", "Insert a sentence, I will say the macheronic latin version");
    printf_s("%s", "Insert sentence: ");
    fgets(sentence, SIZE, stdin);
    sentence[strcspn(sentence, "\r\n")] = 0;

    printLatinWord(sentence);
}

void printLatinWord(const char *sentence)
{
    char *tokenPtr = strtok(sentence, " ");

    while (tokenPtr != NULL)
    {

        int length = strlen(tokenPtr) + 4;
        char token[length];
        char *startCopy = tokenPtr + 1;

        strcpy(token, startCopy);

        strncat(token, tokenPtr, 1);
        strcat(token, "ay");
        strcat(token, " ");
        printf_s("%s", token);
        tokenPtr = strtok(NULL, " ");
    }
}
