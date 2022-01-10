#include <stdio.h>

int main()
{
    int raggio;
    double piGreco = 3.14159;
    printf("%s", "Inserisci il valore del raggio: ");
    scanf("%d", &raggio);

    printf("Perimetro: %f\n", 2*piGreco*raggio);
    printf("Area: %f\n", piGreco*(raggio*raggio));
}
