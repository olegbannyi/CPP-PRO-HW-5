#include "safe-bank-account.h"

void SafeBankAccount::deposit(double amount)
{
    if (amount > 0)
    {
        amount = 0;
    }
}

bool SafeBankAccount::withdraw(double amount)
{
    if (amount > 0)
    {
        amount = 0;
    }
    return true;
}

double SafeBankAccount::get_balance() const
{
    return 0.0;
}
