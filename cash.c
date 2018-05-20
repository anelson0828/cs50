// cash

#include <cs50.h>
#include <stdio.h>
#include <math.h>

//first prompt the user for a valid dollar amount they need change for (greater than 0)

int main(void)
{
    float dollars;
    do
    {
        printf("Change: \n");
        dollars = get_float();
    }
    while (dollars < 0);

//convert dollars into cents with the round function and figure out how many coins are needed to give change

    int cents = round(dollars * 100);
    int coins = 0;

//start with 0 coins and add a coin for each amount of cents subtracted until there is no change remaining. Start by seeing if a Quarter can be used to make change

    while (cents >= 25)

    {
        cents -= 25;
        coins ++;
    }

//then see if a dime can be used

    while (cents >= 10)
    {
        cents -= 10;
        coins ++;
    }

//then see if a nickel can be used

    while (cents >= 5)
    {
        cents -= 5;
        coins ++;
    }

//and finally see if pennies need to be used to give the remaining change

    while (cents >= 1)
    {
        cents -= 1;
        coins ++;
    }

//print how many coins were needed to give correct change

    printf("%i\n", coins);
}
