#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void searchSubString(const char *string, const char *substring);

int main(void)
{
    int lenSentence = malloc(90 * sizeof(char));
    char *sentence = malloc(90 * sizeof(char));
    printf_s("%s", "Insert a sentence: ");
    fgets(sentence, lenSentence, stdin);
    sentence[strcspn(sentence, "\r\n")] = 0;

    int len = strlen(sentence);
    char *finalSentence = malloc((len + 1) * sizeof(char));
    strcpy(finalSentence, sentence);
    free(sentence);

    char *substring = malloc(90 * sizeof(char));
    printf_s("%s", "Insert a substring to search in the first: ");
    fgets(substring, lenSentence, stdin);
    substring[strcspn(substring, "\r\n")] = 0;

    len = strlen(substring);
    char *finalSubString = malloc((len + 1) * sizeof(char));
    strcpy(finalSubString, substring);
    free(substring);
    searchSubString(finalSentence, finalSubString);
}

void searchSubString(const char *string, const char *substring)
{
    char *searchPtr = strstr(string, substring);
    if (searchPtr != NULL)
    {
        printf_s("\n%s%s", "the substring is present and it is: ", searchPtr);
        int i = 1;
        do
        {
            searchPtr = strstr(searchPtr + i, substring);
            if (searchPtr != NULL)
            {
                i++;
                printf_s("\n%s%s", "the substring is present and it is: ", searchPtr);
            }

        } while (searchPtr != NULL);
    }
    else
    {
        printf_s("\n%s", "the substring is not present in first sentence!");
    }
}
