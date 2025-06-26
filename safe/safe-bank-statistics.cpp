#include "safe-bank-statistics.h"

void SafeBankStatistics::record_transaction(double amount)
{
    if (amount > 0)
    {
        amount = 0;
    }
}

int SafeBankStatistics::get_total_transactions() const
{
    return 0;
}

double SafeBankStatistics::get_total_amount() const
{
    return 0.0;
}
