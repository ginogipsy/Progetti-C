#include <stdio.h>

int main()
{
    float galloni;
    unsigned int miglia;
    float media;
    unsigned int count;

    galloni = 1.0f;
    miglia = 0;
    media = 0.0f;
    count = 0;

    while(galloni > 0)
    {
        printf_s("%s", "\nInserire il numero di galloni usati: ");
        scanf("%f", &galloni);

        if(galloni >=1)
        {
            printf("%s", "Inserire il numero di miglia percorse: ");
            scanf("%d", &miglia);
            float mediaTemp = (float) miglia / galloni;
            printf("la media temporanea corrisponde a %.2f\n", mediaTemp);
            media = media + mediaTemp;

        count++;
        }


    }

    printf("\nLa media miglia/galloni corrisponde a: %.6f m/g", media/count);
}
