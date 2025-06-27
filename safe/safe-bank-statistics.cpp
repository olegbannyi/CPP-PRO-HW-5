#include "safe-bank-statistics.h"

void SafeBankStatistics::record_transaction(double amount)
{
    transaction_count_++;
    total_amount_.fetch_add(amount);
}

int SafeBankStatistics::get_total_transactions() const
{
    return transaction_count_;
}

double SafeBankStatistics::get_total_amount() const
{
    return total_amount_;
}
