#include "banking/Account.hpp"
#include <stdexcept>

namespace banking {

Account::Account(int id, double initial_balance)
    : id_(id), balance_(initial_balance) {}

int Account::getId() const {
    return id_;
}

double Account::getBalance() const {
    return balance_;
}

void Account::deposit(double amount) {
    if (amount < 0) {
        throw std::invalid_argument("Deposit amount must be positive");
    }
    balance_ += amount;
}

bool Account::withdraw(double amount) {
    if (amount < 0) {
        throw std::invalid_argument("Withdraw amount must be positive");
    }
    if (amount > balance_) {
        return false;
    }
    balance_ -= amount;
    return true;
}

} // namespace banking 
