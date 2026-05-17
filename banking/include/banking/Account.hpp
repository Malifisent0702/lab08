#ifndef BANKING_ACCOUNT_HPP
#define BANKING_ACCOUNT_HPP

#include <string>

namespace banking {

class Account {
public:
    explicit Account(int id, double initial_balance = 0.0);
    virtual ~Account() = default;

    int getId() const;
    double getBalance() const;

    virtual void deposit(double amount);
    virtual bool withdraw(double amount);

private:
    int id_;
    double balance_;
};

}

#endif()
