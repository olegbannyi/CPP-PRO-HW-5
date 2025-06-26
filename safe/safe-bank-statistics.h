#pragma once

#include <atomic>
class SafeBankStatistics
{
  private:
    std::atomic<int> transaction_count{0}; // TODO: Використайте atomic
    std::atomic<double> total_amount{0.0}; // TODO: Використайте atomic

  public:
    void record_transaction(double amount);
    int get_total_transactions() const;
    double get_total_amount() const;
};
