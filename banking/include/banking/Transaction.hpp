#ifndef BANKING_TRANSACTION_HPP
#define BANKING_TRANSACTION_HPP

#include "banking/Account.hpp"

namespace banking {

class Transaction {
public: 
    static bool transfer(Account& from, Account& to, double amount);
};

} // namespace banking 

#endif // BANKING_TRANSACTION_HPP
