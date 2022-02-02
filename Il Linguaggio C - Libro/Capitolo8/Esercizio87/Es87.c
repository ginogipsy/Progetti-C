#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define SIZE 90

int main(void)
{
    printf_s("%s\n","Inserisci 4 numeri in virgola mobile e li sommo per te");
    double somma = 0.0;
    for(size_t i=0;i<4;i++)
    {
        printf_s("\n%s%d%s","Inserisci il ",i+1," in virgola mobile: ");
        char inserimento[SIZE];
        char *endStr;
        fgets(inserimento, SIZE, stdin);
        somma = somma + strtod(inserimento, &endStr);
    }

    printf_s("\n%s%.2f","Somma dei valori inseriti: ", somma);
}
