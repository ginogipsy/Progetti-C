#include <stdlib.h>

int integerPower(int base, int exponent);

int main(void)
{
    int base = 0;
    int esponente = 0;
    int risultato = 0;

    while(base >= 0)
    {
        printf("%s", "Inserisci una base e un esponente, li calcolero' per te(inserisci -1 -1 per chiudere il programma): ");
        scanf("%d%d", &base, &esponente);

        if(base < 0)
        {
            printf("%s", "Arrivederci!\n");
            break;
        }


        risultato = integerPower(base, esponente);
        printf("%s%d\n", "Il numero che ho calcolato risulta: ", risultato);
    }

}

int integerPower(int base, int exponent)
{
    int total = base;

    for (unsigned i = 1; i < exponent; i++)
    {
        total = total * base;
    }

    return total;

}
