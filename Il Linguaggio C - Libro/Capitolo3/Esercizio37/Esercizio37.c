#include <stdio.h>

int main()
{
    unsigned int x;
    unsigned int y;
    unsigned i;
    unsigned power;

    print_f("%s", "inserire un valore senza segno:");
    scan_f("%u", &x);

    print_f("%s", "inserire un valore senza segno:");
    scan_f("%u", &y);

    i = 1;
    power=1;

    power *= x;
    i++;


    while(i<=y)
    {
        power *= x;
        i++;
    }

    print_f("%u", power);
}

