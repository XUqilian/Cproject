#include <iostream>
#include "head.h"

Savers::Savers(const char *accounts, const char *names, double moneys)
{
    int x = 0;
    while (names[x] != '\0')
    {
        name[x] = names[x];
        x++;
    }
    x = 0;
    while (accounts[x] != '\0')
    {
        account[x] = accounts[x];
        x++;
    }
    money = moneys;
}

void Savers::deposit(double moneys)
{
    if (moneys > 0)
        money += moneys;
    else
        printf("error deposit! bye.");
}

void Savers::remove(double moneys)
{
    if (moneys < money)
        money -= moneys;
    else
        printf("you account doesn't have that much! bye.");
}

void Savers::display() const
{
    printf("name:%s\naccount:%s\nmoney:%f\n", name, account, money);
}