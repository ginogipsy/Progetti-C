#include <stdio.h>

void hanoiTowerMovement(int nDischiDaSpostare, int pioloDiPartenza, int pioloDiArrivo, int pioloTemporaneo);

int main(void)
{
    int nDischiDaSpostare = 3;
    int pioloDiPartenza = 1;
    int pioloDiArrivo = 3;
    int pioloTemporaneo = 2;
    hanoiTowerMovement(nDischiDaSpostare, pioloDiPartenza, pioloDiArrivo, pioloTemporaneo);
}

void hanoiTowerMovement(int nDischiDaSpostare, int pioloDiPartenza, int pioloDiArrivo, int pioloTemporaneo)
{
    if(nDischiDaSpostare == 1)
    {
        printf("%d%s%d\n", nDischiDaSpostare, " -> ", pioloDiArrivo);
    }
    else
    {
        printf("%d%s%d\n", nDischiDaSpostare, " -> ", pioloDiArrivo);
        hanoiTowerMovement(nDischiDaSpostare -1 , pioloDiPartenza, pioloDiArrivo-1, pioloTemporaneo);
    }
}
