#pragma once

#include <mutex>

class SafeBankAccount
{
  private:
    double balance = 1000.0;
    mutable std::mutex balance_mutex;

  public:
    void deposit(double amount);
    bool withdraw(double amount);
    double get_balance() const;
};
