#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateQuestion();
void valuateAnswer(int answer);

int main(void)
{
    srand(time(NULL));
    int answer = 0;
    generateQuestion();
    while (answer >= 0)
    {
        printf("%s", "Insert -1 to stop, 0 to continue with another question: ");
        scanf("%d", &answer);

        if (answer >= 0)
        {
            generateQuestion();
        }
    }
    printf("%s\n", "Good bye");
}

int generateQuestion()
{

    int fattore1 = 1 + rand() % 10;
    int fattore2 = 1 + rand() % 10;
    int answer;
    int isCorrect = 0;

    printf("How much is %d times %d?\n", fattore1, fattore2);
    scanf("%d", &answer);

    while (isCorrect != 1)
    {
        if (answer == fattore1 * fattore2)
        {
            isCorrect = 1;
            valuateAnswer(isCorrect);

        }
        else
        {
            valuateAnswer(isCorrect);
            scanf("%d", &answer);
        }
    }

    return isCorrect;
}

void valuateAnswer(int answer)
{
    int choice = 1 + rand() % 4;
    if (answer == 1)
    {
        switch (choice)
        {
        case 1:
            printf("%s\n", "Very good!");
            break;
        case 2:
            printf("%s\n", "Excellent!");
            break;
        case 3:
            printf("%s\n", "Nice work!");
            break;
        case 4:
            printf("%s\n", "Keep up the good work");
            break;
        }
    }
    else
    {
        switch (choice)
        {
        case 1:
            printf("%s\n", "No. Please try again.");
            break;
        case 2:
            printf("%s\n", "Wrong, Try once more.");
            break;
        case 3:
            printf("%s\n", "Don't give up!");
            break;
        case 4:
            printf("%s\n", "No. Keep trying.");
            break;
        }
    }
}
