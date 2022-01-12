#include <stdlib.h>
#include <math.h>

int isPrimeNumber(int number);
int isPrimeNumbe2(int number);

int main(void)
{
    for (int i = 1; i <= 100000; i++)
    {
        printf("%d%s", i, " = ");

        int isPrime = isPrimeNumber2(i);

        if (isPrime == 1)
        {
            printf("%s\n", "it's prime!");
        }
        else
        {
            printf("%s\n", "it's NOT prime!");
        }
    }
}

int isPrimeNumber(int number)
{
    if (number == 1)
    {
        return 1;
    }

    if (number == 2)
    {
        return 1;
    }

    if (number % 2 != 0)
    {

        for (int i = 3; i < number/2; i=i+2)
        {
            if (number % i == 0)
            {
                return 0;
            }
        }

        return 1;
    }

    return 0;
}

int isPrimeNumber2(int number)
{
    if (number == 1)
    {
        return 1;
    }

    if (number == 2)
    {
        return 1;
    }

    if (number % 2 != 0)
    {

        for (int i = 3; i < sqrt(number); i=i+2)
        {
            if (number % i == 0)
            {
                return 0;
            }
        }

        return 1;
    }

    return 0;
}
