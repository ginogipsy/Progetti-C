#include <stdio.h>

void hanoiTowerMovement(int nDischiDaSpostare, int pioloDiPartenza, int pioloDiArrivo, int pioloTemporaneo);

int main(void)
{
    int nDischi = 4;
    int partenza = 1;
    int arrivo = 3;
    int temporaneo = 2;
    hanoiTowerMovement(nDischi, partenza, arrivo, temporaneo);
}

void hanoiTowerMovement(int nDischi, int partenza, int arrivo, int temporaneo)
{
    if(nDischi == 1)
    {
        printf("%d%s%d\n", partenza, " -> ", arrivo);
    }
    else
    {
        hanoiTowerMovement(nDischi -1, partenza, temporaneo, arrivo);
        printf("%d%s%d\n", partenza, " -> ", arrivo);
        hanoiTowerMovement(nDischi -1 , temporaneo, arrivo, partenza);
    }
}
