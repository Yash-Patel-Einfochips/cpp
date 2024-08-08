#include "Trust_Account.h"
#include "Savings_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account {name, balance, int_rate}, no_of_withdrawls {0} {
}

bool Trust_Account::deposit(double amount) {
    amount = (amount >= def_th) ? (amount + def_bonus) : amount;
    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount) {
    if (no_of_withdrawls >= max_withdrawls || (amount > balance * balance_amount))
        return false;
    else {
        ++no_of_withdrawls;
        return Savings_Account::withdraw(amount);
    }
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
}

