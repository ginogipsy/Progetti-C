#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 36000

int main(void)
{
    int countResult[10] = {0};
    srand(time(NULL));

    for (size_t i = 0; i < SIZE; i++)
    {

        int tiro1 = 1 + rand() % 6;
        int tiro2 = 1 + rand() % 6;
        int result = tiro1 + tiro2;

        switch (result)
        {
        case 2:
            countResult[0]++;
            break;

        case 3:
            countResult[1]++;
            break;
        case 4:
            countResult[2]++;

            break;
        case 5:
            countResult[3]++;
            break;
        case 6:
            countResult[4]++;
            break;
        case 7:
            countResult[5]++;
            break;
        case 8:
            countResult[6]++;
            break;
        case 9:
            countResult[7]++;
            break;
        case 10:
            countResult[8]++;
            break;
        case 11:
            countResult[9]++;
            break;
        case 12:
            countResult[10]++;
            break;
        }
    }

    for (size_t i = 0; i < 11; i++)
    {
        printf("%s%2d: %4d\n", "Risultato ", i+2, countResult[i]);
    }

}
