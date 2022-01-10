#include<stdio.h>

int main(void)
{
    unsigned int row;
    unsigned int lato;

    printf("%s", "Inserisci il valore del lato di un quadrato: ");
    scanf("%d", &lato);

    row = lato;

    while(row>=1)
    {
        unsigned int column = lato;

        while (column >= 1)
        {
            if(column == 1)
            {
                printf("%s", "*");
            }

            else if(column == lato)
            {
                printf("%s", "*");
            }

            else
            {
                if(row == lato)
                {
                    printf("%s", "*");
                }

                else if(row == 1)
                {
                    printf("%s", "*");
                }
                else
                {
                    printf("%s", " ");
                }

            }


            --column;
        }

        --row;
        puts("");

    }
}
