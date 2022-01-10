#include <stdio.h>

int main()
{
    int n;
    printf("%s", "Inserisci un numero di 5 cifre: ");
    scanf("%d", &n);

    int temp;
    //12345
    int a = n/10000;
    temp = n%10000;

    int b = temp/1000;
    temp = temp%1000;

    int c = temp/100;
    temp = temp%100;

    int d = temp/10;



    printf("\n%d\n", n);
    printf("%d\n", a);
    printf("%d\n", temp);
    printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d", a, b,c,d,temp%10);
}
