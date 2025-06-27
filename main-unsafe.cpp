#include "unsafe/unsafe-bank-account.h"
#include "unsafe/unsafe-bank-statistics.h"
#include <chrono>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <format>
#include <fstream>
#include <functional>
#include <iostream>
#include <random>
#include <sstream>
#include <thread>
#include <vector>

void cashier_work(int, UnsafeBankAccount &, UnsafeBankStatistics &);

int main()
{
    UnsafeBankAccount account;
    UnsafeBankStatistics statistics;
    double initial_balance{account.get_balance()};

    std::vector<std::thread> threads;

    for (size_t id = 1; id <= 5; ++id)
    {
        threads.emplace_back(cashier_work, id, std::ref(account), std::ref(statistics));
    }

    for (auto &t : threads)
    {
        t.join();
    }

    std::cout << std::fixed;
    std::cout << std::setprecision(2);

    std::cout << "=== Bank Simulation Results (Unsafe) ===\n"
              << "Initial balance: " << initial_balance << "\n"
              << "Final balance: " << account.get_balance() << "\n"
              << "Total transactions: " << statistics.get_total_transactions() << "\n"
              << "Total transaction amount: " << statistics.get_total_amount() << "\n"
              << "All cashiers completed work unsafely!" << std::endl;

    return 0;
}

void cashier_work(int cachier_id, UnsafeBankAccount &account, UnsafeBankStatistics &statistics)
{
    std::stringstream log;
    std::mt19937_64 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<double> dist_deposit(50.0, 500.0);
    std::uniform_real_distribution<double> dist_withdraw(10.0, 200.0);

    double amount{};
    bool succes{};

    for (size_t i = 0; i < 100; ++i)
    {
        amount = dist_deposit(rng);
        account.deposit(amount);
        statistics.record_transaction(amount);
        log << std::format("{:03d} deposite: {:.2f}, balance: {:.2f}\n", i, amount,
                           account.get_balance());

        amount = dist_withdraw(rng);
        succes = account.withdraw(amount);
        statistics.record_transaction(amount);
        log << std::format("    withdraw: {:.2f}, success: {}, balance: {:.2f}\n\n", amount, succes,
                           account.get_balance());
    }

    std::ofstream logfile(std::format("build/unsafe/cachier-{}.log", cachier_id));

    if (logfile.is_open())
    {
        logfile << log.str() << std::endl;
        logfile.close();
    }
    else
    {
        std::cout << "Unable to write log file" << std::endl;
    }
}
