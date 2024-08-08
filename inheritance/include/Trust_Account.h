#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_
#include "Savings_Account.h"

class Trust_Account: public Savings_Account {
    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Savings Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    static constexpr double def_th = 5000;
    static constexpr double def_bonus = 50.0;
    static constexpr int max_withdrawls = 3;
    static constexpr double balance_amount = 0.2;
protected:
    double no_of_withdrawls;
public:
    Trust_Account(std::string name = def_name, double balance =def_balance, double int_rate = def_int_rate);    
    bool deposit(double amount);
    // Inherits the Account::withdraw methods
    bool withdraw(double amount);
};

#endif // _SAVINGS_ACCOUNT_H_
