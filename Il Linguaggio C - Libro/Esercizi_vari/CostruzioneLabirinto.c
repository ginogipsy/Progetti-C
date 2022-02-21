#include <stdio.h>
#include <time.h>

void generaLabirinto(char *labirinto, unsigned int altezza, unsigned int larghezza);
void stampaLabirinto(char *labirinto, unsigned int altezza, unsigned int larghezza);


int main(void)
{
    srand(time(NULL));
    int larghezza = 12;
    int altezza = 12;
    char *labirinto;
    generaLabirinto(labirinto, altezza, larghezza);
    stampaLabirinto(labirinto, altezza, larghezza);
    

}

void generaLabirinto(char *labirinto, unsigned int altezza, unsigned int larghezza)
{
    char lab[altezza][larghezza];
    unsigned int ingressoCasuale = 1 + rand() % (altezza-1);
    unsigned int uscitaCasuale = 1 + rand() % (altezza-1);

    for(size_t i = 0;i<altezza;i++)
    {
        for(size_t j = 0; j<larghezza;j++)
        {
            if(0 == i || (altezza-1) == i)
            {
                lab[i][j] = '#';
            }

            else if(0 == j)
            {
                if(ingressoCasuale == i)
                {
                    lab[i][j] = '.';
                }
                else
                {
                    lab[i][j] = '#';
                }
            }

            else if((larghezza - 1) == j)
            {
                if(uscitaCasuale == i)
                {
                    lab[i][j] = '.';
                }else
                {
                    lab[i][j] = '#';
                }
            }
            else
            {
                lab[i][j] = '.';
            }
        }
    }
    *labirinto = &lab;
}

void stampaLabirinto(char *labirinto, unsigned int altezza, unsigned int larghezza)
{
    int count = 0;
    //char lab[altezza][larghezza] = labirinto;
    for(size_t i = 0; i<altezza; i++)
    {
        for (size_t j = 0; j < larghezza; j++)
        {
            printf("%s", labirinto + count);
            count++;
        }

        printf("%c", '\n');      
    }
    
}
