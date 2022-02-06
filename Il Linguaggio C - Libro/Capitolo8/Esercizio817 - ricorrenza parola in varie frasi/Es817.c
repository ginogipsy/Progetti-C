#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50
int searchSubString(const char *string, const char *substring);

int main(void)
{
    char *sentences[SIZE];


    int lenSentence = malloc(90 * sizeof(char));
    char *sentence = malloc(90 * sizeof(char));

    int count = 0;
    while (0 == 0)
    {


        printf_s("%s", "Insert a sentence(or -1 to stop): ");
        fgets(sentence, lenSentence, stdin);
        sentence[strcspn(sentence, "\r\n")] = 0;

        if(strtol(sentence, NULL,0) == -1)
        {
            free(sentence);
            break;
        }

        int len = strlen(sentence);
        char *finalSentence = malloc((len + 1) * sizeof(char));
        strcpy(finalSentence, sentence);
        sentence = malloc(90 * sizeof(char));
        sentences[count] = finalSentence;
        count++;

    }

    char *substring = malloc(90 * sizeof(char));
    printf_s("%s", "Insert a substring to search in the first: ");
    fgets(substring, lenSentence, stdin);
    substring[strcspn(substring, "\r\n")] = 0;

    int len = strlen(substring);
    char *finalSubString = malloc((len + 1) * sizeof(char));
    strcpy(finalSubString, substring);
    free(substring);

    int i=0;
    int times = 0;
    while(i<count)
    {
        times += searchSubString(sentences[i], finalSubString);
        i++;
    }
    printf_s("\n%s%s%s%d%s","the substring ", finalSubString, " appears in the sentences ", times, " times!");
}

int searchSubString(const char *string, const char *substring)
{
    int times = 0;
    char *searchPtr = strstr(string, substring);
    if (searchPtr != NULL)
    {
        printf_s("\n%s%s", "the substring is present and it is: ", searchPtr);
        times++;
        do
        {
            searchPtr = strstr(searchPtr + times, substring);
            if (searchPtr != NULL)
            {
                times++;
                printf_s("\n%s%s", "the substring is present and it is: ", searchPtr);
            }

        } while (searchPtr != NULL);
        return times;
    }
    else
    {
        printf_s("\n%s", "the substring is not present in first sentence!");
        return 0;
    }
}
