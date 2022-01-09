#include <stdio.h>

int main()
{
    int numeri = 0;
    int count = 0;
    int minore = 0;
    int num = 0;

    printf("%s", "Inserisci quanti numeri vuoi inserire e ti dico il minore: ");
    scanf("%d", &numeri);

    while(count <= numeri)
    {
        printf("%s", "Inserisci un numero intero:");
        scanf("%d", &num);

        if(count == 0 || num < minore)
        {
            minore = num;
        }

        count++;
    }

    printf("Il numero minore che hai inserito risulta: %d", minore);
    }
