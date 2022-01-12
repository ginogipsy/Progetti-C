#include <stdlib.h>

int verificaNumeroPerfetto(int number);

int main(void)
{
    for (int i = 2; i < 100000; i++)
    {
        printf("%d%s",i, " = ");

        int isPerfect = verificaNumeroPerfetto(i);
        if (isPerfect == 1)
        {
            printf("%s\n", "Perfect!");
        }
        else
        {
            printf("%s\n", "Oh no! i'm sorry!");
        }

    }
}

int verificaNumeroPerfetto(int number)
{
    int total = 0;
    int firstNumber = 0;

    if(number % 2 == 0)
    {
        firstNumber = number/2;
    }
    else
    {
        firstNumber = (number + 1) /2;
    }


    for (int i = firstNumber; i > 0; i--)
    {
        if (number % i == 0)
        {
            total += i;
            if(i != 1)
            {
                printf("%d%s", i, " + ");
            }
            else
            {
                printf("%d%s", i, ": ");
            }

        }
    }

    if (total == number)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
