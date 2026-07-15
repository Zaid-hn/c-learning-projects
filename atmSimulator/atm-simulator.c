#include <stdio.h>
#include <stdbool.h>

int cash_amt();
int money_validation(int amount);

int main()
{
    int balance = 1000;
    int choice = 1;

    while (choice != 0)
    {
        printf("\n-------------------------\n");
        printf("      ATM Simulator      ");
        printf("\n-------------------------\n\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("0. Exit\n");

        printf("\n> Select option: ");
        scanf("%d", &choice);
        printf("\n");

        if (choice == 1)
        {
            printf("> Your balance is %d\n", balance);
        }
        else if (choice == 2)
        {
            printf("> Deposit amount: ");
            int temp_money = cash_amt();
            if (money_validation(temp_money))
            {
                balance += temp_money;
                printf("\n> Successfully Deposited!\n\n");
                printf("> Account balance: %d\n", balance);
            }
        }
        else if (choice == 3)
        {
            printf("> Withdraw amount: ");
            int temp_money = cash_amt();
            if (money_validation(temp_money))
            {
                if (temp_money <= balance)
                {
                    balance -= temp_money;
                    printf("\n> Withdrawal successful!\n");
                    printf("\n> Account balance: %d\n", balance);
                }
                else
                {
                    printf("\n> Insufficient balance\n");
                }
            }
        }
        else if (choice == 0)
        {
            printf("> Thank you for using our ATM!\n\n");
        }
        else
        {
            printf("\n> Wrong option...\n");
        }
    }

    return 0;
}

int cash_amt()
{
    int temp_money;
    scanf("%d", &temp_money);
    return temp_money;
}

int money_validation(int amount)
{
    if (amount > 0)
    {
        return 1;
    }
    else
    {
        printf("\n> Cannot withdraw a negative amount!!\n");
        return 0;
    }
}