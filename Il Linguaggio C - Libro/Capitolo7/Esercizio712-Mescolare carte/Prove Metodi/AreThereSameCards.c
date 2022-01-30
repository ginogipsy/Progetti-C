#include <stdio.h>
#define HAND 5

int valuatePoint(int numberFirstSet, int equalsCard1, int equalsCard2);
int isSameColor(unsigned int suits[HAND]);
int straight(unsigned int faces[HAND]);

int main(void)
{
    int faces[HAND] = {2,4,5,6,7};
    int suits[HAND] = {3,3,2,3,3};
    unsigned int equalsCard1 = 1;
    int numberFirstSet = -1;
    unsigned int equalsCard2 = 1;
    int numberSecondSet = -1;

    for(size_t i=1;i<HAND;i++)
    {
       if(faces[i] == faces[i-1])
       {
           if(numberFirstSet == -1 || numberFirstSet == faces[i])
           {
               numberFirstSet = faces[i];
               equalsCard1++;
           }
           else
           {
               numberSecondSet = faces[i];
               equalsCard2++;
           }
       }
    }

    int result = valuatePoint(numberFirstSet, equalsCard1, equalsCard2);
    int resultColor = isSameColor(suits);
    int resultStraight = straight(faces);
    printf("\n%s%d\n", "numberFirstSet: ", numberFirstSet);
    printf("\n%s%d\n", "numberSecondSet: ", numberSecondSet);
    printf("\n%s%d\n", "equalsCard1: ", equalsCard1);
    printf("\n%s%d\n", "equalsCard2: ", equalsCard2);
    printf("\n%s%d\n", "result: ", result);
    printf("\n%s%d\n", "resultColor: ", resultColor);
    printf("\n%s%d\n", "resultStraight: ", resultStraight);

}

//torna un int con il punto del risultato
//0: 0 carte uguali
//1: coppia
//2: doppia coppia
//3: tris
//5: full
//6: poker
int valuatePoint(int numberFirstSet, int equalsCard1, int equalsCard2)
{
    if(numberFirstSet != -1)
    {
        if(equalsCard1 == 2)
        {
            if(equalsCard2 == 2)
            {
                return 2;
            }
            if(equalsCard2 == 3)
            {
                return 5;
            }
            else
            {
            return 1;
            }
        }

        if(equalsCard1 == 3)
        {
            if(equalsCard2 == 2)
            {
                return 5;
            }
            else
            {
                return 3;
            }
        }
        if(equalsCard1 >= 4)
        {
            return 6;
        }
    }
    else
    {
        return 0;
    }
}

int isSameColor(unsigned int suits[HAND])
{
    int sameColor = 1;
  for (size_t i = 0; i < HAND - 1; ++i)
    {
        if (suits[i] != suits[i + 1])
        {
            return 0;
        }
    }

    return sameColor;
}

int straight(unsigned int faces[HAND])
{
     for(size_t i = 0; i < HAND -1; i++)
    {
            if ((faces[i + 1] - faces[i]) != 1)
            {
                return 0;
            }
    }

    return 1;

}
