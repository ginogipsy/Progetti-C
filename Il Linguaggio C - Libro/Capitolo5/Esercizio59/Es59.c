#include <stdio.h>

double calcolaCostoParcheggio(double ore);

int main(void)
{
    double oreParcheggio1 = 0.0;
    double oreParcheggio2 = 0.0;
    double oreParcheggio3 = 0.0;
    double oreTotali = 0.0;
    double costoParcheggio1 = 0.0;
    double costoParcheggio2 = 0.0;
    double costoParcheggio3 = 0.0;
    double costoTotale = 0.0;

    
        printf("%s", "Inserisci le ore dei tre clienti: ");
        scanf("%f%f%f", &oreParcheggio1, &oreParcheggio2, &oreParcheggio3);

        oreTotali = oreParcheggio1+oreParcheggio2+oreParcheggio3;

        costoParcheggio1 = calcolaCostoParcheggio(oreParcheggio1);
        costoParcheggio2 = calcolaCostoParcheggio(oreParcheggio2);
        costoParcheggio3 = calcolaCostoParcheggio(oreParcheggio3);
        costoTotale = costoParcheggio1 + costoParcheggio2 + costoParcheggio3;

        printf("%10s%10s%10s:\n", "Car, Hours, Total");
        printf("%10.2f%10.2f%10.2f", 1, oreParcheggio1, costoParcheggio1);
        printf("%10.2f%10.2f%10.2f", 2, oreParcheggio2, costoParcheggio2);
        printf("%10.2f%10.2f%10.2f", 3, oreParcheggio3, costoParcheggio3);
        printf("%10s%10.2f%10.2f","TOTAL", oreTotali, costoTotale);
}

double calcolaCostoParcheggio(double oreParcheggio)
{
    double costoTotale = 0.0;
    if(oreParcheggio <= 3.0)
    {
        return 2.0;
    }
    
    costoTotale += 2.0;
    oreParcheggio -= 3.0;

    /*while (oreParcheggio <= 0)
    {
       oreParcheggio -= 1.0;
       costoTotale += 0.5;
    }*/
    costoTotale = costoTotale +((int) oreParcheggio % 1 * 0.5);

    if(oreParcheggio - (int) oreParcheggio != 0)
    {
        costoTotale += 0.5;
    }

    if(costoTotale <= 10.0)
    {
        return costoTotale;
    }else
    {
        return 10.0;
    }
}