#include <stdio.h>

int main()
{

    printf("\n------TRIVIA QUIZ------\n\n");
    printf("> Question 1\n");

    printf(">> What is the capital of Japan?\n\n");

    printf("1. Osaka\n");
    printf("2. Korea\n");
    printf("3. Tokyo\n");
    printf("4. Beijing\n\n");

    int answer;
    printf("> ");
    scanf("%i", &answer);

    if (answer == 3)
    {
        printf("\nCorrect Answer!\n");
    }
    else
    {
        printf("\nWrong answer:(\n");
    }

    return 0;
}
