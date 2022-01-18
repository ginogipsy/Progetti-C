#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateQuestion(int countAnswers, int difficulty, int operationType);
void valuateAnswer(int answer);
void valuateStudent(int correctAnswer, int countAnswers);

int main(void)
{
    srand(time(NULL));
    int countAnswers = 0;
    int correctAnswer = 0;
    int difficulty;
    int operationType;

    printf("%s", "Please, insert a difficult level:\n(1: max 9 - 2: max 99 - 3: max 999)\n");
    scanf("%d", &difficulty);

    printf("%s", "Please, insert operation type:\n(1: addition - 2: subtraction - 3: multiplication)\n");
    scanf("%d", &operationType);

    countAnswers = generateQuestion(countAnswers, difficulty, operationType);

    if (countAnswers < 10)
    {
        correctAnswer++;
    }

    while (countAnswers < 10)
    {
        countAnswers = generateQuestion(countAnswers, difficulty, operationType);
        if (countAnswers < 10)
        {
            correctAnswer++;
        }
    }

    valuateStudent(correctAnswer, 10);
    printf("%s\n", "Good bye");
}

int generateQuestion(int countAnswers, int difficulty, int operationType)
{
    int difficultyModificator;
    if (difficulty == 1)
    {
        difficultyModificator = 9;
    }
    else if (difficulty == 2)
    {
        difficultyModificator = 99;
    }
    else
    {
        difficultyModificator = 999;
    }

    if (operationType == 4)
    {
        operationType = 1 + rand() % 3;
    }

    int fattore1 = 1 + rand() % difficultyModificator;
    int fattore2 = 1 + rand() % difficultyModificator;
    int answer;
    int isCorrect = 0;
    int countAnswer = countAnswers;

    switch (operationType)
    {
    case 1:
        printf("How much is %d + %d?\n", fattore1, fattore2);
        break;
    case 2:
        printf("How much is %d - %d?\n", fattore1, fattore2);
        break;
    case 3:
        printf("How much is %d times %d?\n", fattore1, fattore2);
        break;

    default:
        break;
    }

    scanf("%d", &answer);

    while (isCorrect < 1 && countAnswer < 10)
    {
        countAnswer++;
        if (1 == valuateResult(operationType, fattore1, fattore2, answer))
        {
            isCorrect = 1;
            valuateAnswer(isCorrect);
        }
        else
        {
            valuateAnswer(isCorrect);

            if (countAnswer < 10)
            {
                scanf("%d", &answer);
            }
        }
    }

    if (isCorrect == 0 && countAnswer == 10)
    {
        countAnswer++;
    }

    return countAnswer;
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

void valuateStudent(int correctAnswer, int countAnswers)
{
    double perc = (double)correctAnswer / countAnswers * 100;

    if (perc >= 75)
    {
        printf("%s\n", "Congratulations, you are ready to go to the next level!");
    }
    else
    {
        printf("%s\n", "Please ask your teacher for extra help.");
    }
}

int valuateResult(int operationType, int firstNumber, int secondNumber, int answer)
{
    int result;

    switch (operationType)
    {
    case 1:
        result = (answer == firstNumber + secondNumber);
        break;
    case 2:
        result = (answer == firstNumber - secondNumber);
        break;
    case 3:
        result = (answer == firstNumber * secondNumber);
        break;
    }

    return result;
}
