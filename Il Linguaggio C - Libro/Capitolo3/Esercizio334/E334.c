#include<stdio.h>

int main(void)
{
    unsigned int numero;
    unsigned int temp;
    unsigned int primo;
    unsigned int secondo;
    unsigned int terzo;
    unsigned int quarto;
    unsigned int quinto;


    printf("%s", "Inserisci un numero di 5 cifre: ");
    scanf("%d", &numero);

    primo = numero / 10000;
    temp = numero % 10000;

    secondo = temp / 1000;
    temp = temp % 1000;

    terzo = temp / 100;
    temp = temp % 100;

    quarto = temp / 10;

    quinto = temp % 10;


    temp = quinto * 10000 + quarto * 1000 + terzo * 100 + secondo * 10 + primo;

    printf("Il numero 1: %d\n", primo);
    printf("Il numero 2: %d\n", secondo);
    printf("Il numero 3: %d\n", terzo);
    printf("Il numero 4: %d\n", quarto);
    printf("Il numero 5: %d\n", quinto);

    printf("Il numero temp: %d\n", temp);

    if(temp == numero)
    {
        printf("%s", "Il numero risulta palindromo!");
    }else
    {
        printf("%s", "Il numero NON risulta palindromo!");
    }





}
