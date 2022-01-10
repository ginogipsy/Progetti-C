#include<stdio.h>

int main(void)
{
    unsigned int row = 5;

    while(row>=1)
    {
        unsigned int column = 5;

        while (column >= 1)
        {
             printf("%s", "*");
             --column;
        }

        --row;
        puts("");

    }
}
