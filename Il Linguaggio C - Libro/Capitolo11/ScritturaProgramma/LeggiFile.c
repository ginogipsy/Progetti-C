#include <stdio.h>

int main(void)
{

    FILE *cfPtr;

    if((cfPtr = fopen("clients.txt","r")) == NULL) 
    {
        puts("File could not be opened");
    }
    else 
    {
        unsigned int account;
        char name[30];
        double balance;

        printf("%-10s%-13s%s\n", "Account", "Name", "Balance");
        fscanf(cfPtr,"%d%29s%lf", &account, name, &balance);

        while (!feof(cfPtr))
        {
            printf("%-10d%-13s%7.2f\n", account, name, balance);
            fscanf(cfPtr, "%d%29s%lf", &account, name, &balance);
        }

        fclose(cfPtr);        
    }
}