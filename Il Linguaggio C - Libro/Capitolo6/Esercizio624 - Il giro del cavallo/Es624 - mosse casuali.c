#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

int move(int position[2], int board[SIZE][SIZE]);
void viewBoard(int board[SIZE][SIZE]);

int main(void)
{
    int board[SIZE][SIZE] = {0};
    int count = 0;
    int moveNumber = 0;
    int position[2] = {0}; //row-column

    srand(time(NULL));
    position[0] = 1 + rand() % 7;
    position[1] = 1 + rand() % 7;

    board[position[0]][position[1]] = 1;

    do
    {
        moveNumber = move(position, board);

        if (moveNumber != -1)
        {
            count++;

            printf("%s%d\n", "currentRow: ", position[0]);
            printf("%s%d\n", "currentColumn: ", position[1]);
        }

    } while (moveNumber != -1);

    printf("%s%d\n", "Total movments: ", count);
    viewBoard(board);
}

void viewBoard(int board[SIZE][SIZE])
{
    int i, j;

    printf("\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",0,1,2,3,4,5,6,7);
    printf("\t%s\n","_________________________________________________________");


    for (i = 0; i < SIZE; ++i)
    {
        printf("%d%s\t",i, "|");
        for (j = 0; j < SIZE; ++j)
            printf("%d\t", board[i][j]);

        printf("\n");
    }
}

int move(int position[2], int board[SIZE][SIZE])
{

    int horizontal[SIZE] = {2, 1, -1, -2, -2, -1, 1, 2};
    int vertical[SIZE] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int tempRow;
    int tempColumn;
    int count = 0;

    do
    {
        if (count == 9)
        {
            count++;
            break;
        }

        tempRow = position[0];
        tempColumn = position[1];

        tempRow += vertical[count];
        tempColumn += horizontal[count];

        count++;
    } while ((tempRow < 0 || tempRow > 8) || (tempColumn < 0 || tempColumn > 8) || board[tempRow][tempColumn] != 0);

    if (count < 10)
    {
        position[0] = tempRow;
        position[1] = tempColumn;
        board[tempRow][tempColumn] = 1;
        return 1;
    }
    else
    {
        printf("%s\n", "Game over!");
        return -1;
    }
}
