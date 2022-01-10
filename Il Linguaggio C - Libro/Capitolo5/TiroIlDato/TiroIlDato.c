#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tiraIlDato(int tipoDato);

int main()
{
    int nTiri = 0;
    int tipoDato = 0;
    int sommaTiri = 0;
    int sommaTotaleTiri = 0;

    printf("%s", "Ciao, questo programma tira il dato per te\n");


    while(tipoDato != -1)
    {
    srand(time(NULL));

    printf("%s", "Che tipo di dato vuoi tirare (numero di facce)?\n(se vuoi smettere di lanciare inserisci -1)\n");
    scanf("%d", &tipoDato);

    if(tipoDato == -1)
    {
        break;
    }

    if(tipoDato < 4 || tipoDato > 20 || tipoDato % 2 != 0)
    {
        printf("%s", "Deve essere un intero pari!\n");
        tipoDato = 0;
        continue;
    }



    printf("%s", "Quante volte vuoi tirarlo?\n");
    scanf("%d", &nTiri);


    for(unsigned i=1; i<=nTiri; ++i)
    {
        int temp = tiraIlDato(tipoDato);
        printf("Tiro %3d: %5d\n",i, temp);
        sommaTiri += temp;
    }
    printf("%s", "Perfetto! Faccio la somma dei tiri: \n");
    printf("La somma dei tiri risulta: %d\n", sommaTiri);

    sommaTotaleTiri += sommaTiri;
    sommaTiri = 0;

    }

    printf("%s", "Perfetto! Faccio la somma totale dei tiri: \n");
    printf("La somma totale di tutti i tiri risulta: %d\n", sommaTotaleTiri);


}

int tiraIlDato(int tipoDato)
{
    {
        return 1 + (rand() % tipoDato);
    }
}





