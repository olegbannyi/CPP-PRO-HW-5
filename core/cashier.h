#pragma once

#include "logger.h"
#include <chrono>
#include <random>

class Casher
{
    Logger logger_;

  public:
    explicit Casher(Logger logger) : logger_(std::move(logger))
    {
    }
    template <class BankAccountType, class BankStatisticsType>
    void work(BankAccountType &account, BankStatisticsType &statistics)
    {
        std::mt19937_64 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
        std::uniform_real_distribution<double> dist_deposit(50.0, 500.0);
        std::uniform_real_distribution<double> dist_withdraw(10.0, 200.0);

        double amount{};
        bool succes{};

        for (size_t i = 0; i < 50; ++i)
        {
            amount = dist_deposit(rng);
            account.deposit(amount);
            statistics.record_transaction(amount);
            logger_.write(std::format("{:03d} deposite: {:.2f}, balance: {:.2f}\n", i, amount, account.get_balance()));

            amount = dist_withdraw(rng);
            succes = account.withdraw(amount);
            statistics.record_transaction(amount);
            logger_.write(std::format("    withdraw: {:.2f}, success: {}, balance: {:.2f}\n\n", amount, succes,
                                      account.get_balance()));
        }

        logger_.flash();
    }
};
