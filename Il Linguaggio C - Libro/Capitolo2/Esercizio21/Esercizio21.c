#include <stdio.h>

int main()
{
    int x;
    int y;
    int z;
    int result;

    printf("%s", "Inserisci tre numero interi: ");
    scanf("%d %d %d", &x, &y, &z);
    result = x*y*z;
    printf("The product is %d", result);
}
