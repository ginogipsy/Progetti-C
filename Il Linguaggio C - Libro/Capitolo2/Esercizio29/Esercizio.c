#include <stdio.h>

int main()
{
    printf("%s", "Enter two numbers: ");

    int b;
    int c;
    int a;

    scanf("%d %d", &b, &c);
    a = b*c;
    printf("\n%s %d", "Result of multiplication is: ", a);
}
