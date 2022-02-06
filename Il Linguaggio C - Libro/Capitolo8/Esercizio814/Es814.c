#include <stdio.h>
#include <stdlib.h>

#define SIZE 17

void analyzePhoneNumber(const char *phoneNumber);

int main(void)
{
    char phoneNumber[SIZE] = "";
    printf_s("%s\n", "Insert a phone number, I will say the all the parts");
    printf_s("%s", "Insert a phone number\nwith this format -> (555) 555-5555: ");
    fgets(phoneNumber, SIZE, stdin);
    phoneNumber[strcspn(phoneNumber, "\r\n")] = 0;
    analyzePhoneNumber(phoneNumber);
}

void analyzePhoneNumber(const char *phoneNumber)
{

    int prefix = 0;
    long number = 0;
    char tempNumber[8] = "";

    char *tokenPtr = strtok(phoneNumber, ")");
    int count = 1;
    while (count < 4 || tokenPtr != NULL)
    {
        if (1 == count)
        {
            prefix = (int)strtol(++tokenPtr, NULL, 0);
            tokenPtr = strtok(NULL, "-");
            count++;
        }
        if (count == 2)
        {
            strcpy(tempNumber, tokenPtr);
            tokenPtr = strtok(NULL, " ");
            count++;
        }

        if (count == 3)
        {
            strcat(tempNumber, tokenPtr);
            tokenPtr = strtok(NULL, " ");
            count++;
        }
    }

    number = strtol(&tempNumber, NULL, 0);
    printf("\n%16s%d", "Il prefisso e': ", prefix);
    printf("\n%16s%d", "Il numero e'  : ", number);
}
