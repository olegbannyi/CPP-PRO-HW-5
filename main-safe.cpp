#include "core/bank.h"
#include "core/cashier.h"
#include "core/logger.h"
#include "safe/safe-bank-account.h"
#include "safe/safe-bank-statistics.h"
#include <cstdlib>
#include <format>
#include <iostream>

int main()
{
    SafeBankAccount account;
    SafeBankStatistics statistics;
    double initial_balance{account.get_balance()};

        Bank bank;
        Casher cachier1(Logger(std::format("build/safe/cachier-{}.log", 1)));
        Casher cachier2(Logger(std::format("build/safe/cachier-{}.log", 2)));
        Casher cachier3(Logger(std::format("build/safe/cachier-{}.log", 3)));
        Casher cachier4(Logger(std::format("build/safe/cachier-{}.log", 4)));
        Casher cachier5(Logger(std::format("build/safe/cachier-{}.log", 5)));
        bank.assign<SafeBankAccount, SafeBankStatistics>(cachier1, account, statistics);
        bank.assign<SafeBankAccount, SafeBankStatistics>(cachier2, account, statistics);
        bank.assign<SafeBankAccount, SafeBankStatistics>(cachier3, account, statistics);
        bank.assign<SafeBankAccount, SafeBankStatistics>(cachier4, account, statistics);
        bank.assign<SafeBankAccount, SafeBankStatistics>(cachier5, account, statistics);

        bank.waitAll();

    std::cout << std::fixed;
    std::cout << std::setprecision(2);

    std::cout << "=== Bank Simulation Results (Safe) ===\n"
              << "Initial balance: " << initial_balance << "\n"
              << "Final balance: " << account.get_balance() << "\n"
              << "Total transactions: " << statistics.get_total_transactions() << "\n"
              << "Total transaction amount: " << statistics.get_total_amount() << "\n"
              << "All cashiers completed work safely!" << std::endl;

    return 0;
}
