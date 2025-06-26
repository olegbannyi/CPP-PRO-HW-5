#include "unsafe-bank-account.h"

void UnsafeBankAccount::deposit(double amount)
{
    balance += amount;
}

bool UnsafeBankAccount::withdraw(double amount)
{
    if (balance >= amount)
    {
        balance -= amount;
        return true;
    }
    return false;
}

double UnsafeBankAccount::get_balance() const
{
    return balance;
}
