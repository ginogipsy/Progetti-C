#include <stdio.h>
#include <time.h>

int turtleMovment();
int rabbitMovment();
void printPosition(const int *const turtleMovment,const int *const rabbitMovment);
void winner(const int *const turtleMovment,const int *const rabbitMovment);

int main(void)
{
    srand(time(NULL));
    int turtlePosition = 1;
    int rabbitPosition = 1;
    int move = 0;
    printf_s("\n%s\n", "BANG !!!!!\nAND THEY'RE OFF !!!!!");
    while (0 == 0)
    {
        if(turtlePosition >= 70 || rabbitPosition >= 70)
        {
            winner(&turtlePosition, &rabbitPosition);
            break;
        }
        printf_s("\n%0.2d%s\n",++move, " move!");
        turtlePosition += turtleMovment();
        if(turtlePosition < 1)
        {
            turtlePosition = 1;
        }

        rabbitPosition += rabbitMovment();
        if(rabbitPosition < 1)
        {
            rabbitPosition = 1;
        }

        printPosition(&turtlePosition, &rabbitPosition);
        fflush(stdout);
        sleep(1);
    }
    

}

int turtleMovment()
{
    int casualNumber = 1 + rand() % 10;
    if(casualNumber >= 1 && casualNumber <= 5)
    {
        printf_s("%s\n", "TURTLE: fast pace!");
        return 3;
    }
    else if(casualNumber >= 6 && casualNumber <= 7)
    {
        printf_s("%s\n", "TURTLE: slip!");
        return -6;
    }
    else
    {
        printf_s("%s\n", "TURTLE: slow pace!");
        return 1;
    }
}

int rabbitMovment()
{
    int casualNumber = 1 + rand() % 10;
    if(casualNumber >= 1 && casualNumber <= 2)
    {
        printf_s("%s\n", "RABBIT: rest!");
        return 0;
    }
    else if(casualNumber >= 3 && casualNumber <= 4)
    {
        printf_s("%s\n", "RABBIT: great leap!");
        return 9;
    }
    else if(casualNumber == 5)
    {
        printf_s("%s\n", "RABBIT: great slip!");
        return -12;
    }
    else if(casualNumber >= 6 && casualNumber <= 8)
    {
        printf_s("%s\n", "RABBIT: little leap!");
        return 1;
    }
     else
    {
        printf_s("%s\n", "RABBIT: little slip!");
        return 1;
    }
}

void printPosition(const int *const turtleMovment, const int *const rabbitMovment)
{
    int samePosition = 0;
    if(*turtleMovment == *rabbitMovment)
    {
        samePosition = *turtleMovment;
    }
    //const char sound[6] = "OUCH!";
    const char *sound = "OUCH!";
    int value = 0;
    for(int i = 1; i<=70; i++){
        
        /* if(samePosition > 0 && i == samePosition){
            printf_s("[%c]", sound[value]);
            value++;
        }
        else if(samePosition > 0 && value > 0 && value < 5)
        {
            printf_s("[%c]", sound[value]);
            value++;
        } */
        if(samePosition > 0 && i == samePosition){
            printf_s("[%s]", sound);
        }
        else if(i == *turtleMovment)
        {
            printf_s("%s", "[T]");
        }
        else if(i == *rabbitMovment)
        {
            printf_s("%s", "[R]");
        }
        else
        {
            printf_s("%s", "[ ]");
        }
    }

    puts("");
}
void winner(const int *const turtleMovment,const int *const rabbitMovment)
{
    if(*turtleMovment >= 70 && *rabbitMovment >= 70)
    {
        printf_s("\n%s\n", "TURTLE WINS!!! YAY!!!");
    }
    else if(*turtleMovment >= 70 && *rabbitMovment < 70)
    {
        printf_s("\n%s\n", "TURTLE WINS!!! YAY!!!");
    }
    else if(*rabbitMovment >= 70 && *turtleMovment < 70)
    {
        printf_s("\n%s\n", "Rabbit wins. Yuch.");
    }
}