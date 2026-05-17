#include <gtest/gtest.h>
#include "banking/Account.hpp"

using namespace banking;

TEST(AccountTest, ConstructorAndGetters) {
    Account acc(1, 100.0);
    EXPECT_EQ(acc.getId(), 1);
    EXPECT_DOUBLE_EQ(acc.getBalance(), 100.0);
}

TEST(AccountTest, DefaultBalanceIsZero) {
    Account acc(2);
    EXPECT_DOUBLE_EQ(acc.getBalance(), 0.0);
}

TEST(AccountTest, Deposit) {
    Account acc(1, 100.0);
    acc.deposit(50.0);
    EXPECT_DOUBLE_EQ(acc.getBalance(), 150.0);
}

TEST(AccountTest, DepositNegativeThrows) {
    Account acc(1, 100.0);
    EXPECT_THROW(acc.deposit(-10.0), std::invalid_argument);
}

TEST(AccountTest, WithdrawSuccess) {
    Account acc(1, 100.0);
    bool result = acc.withdraw(30.0);
    EXPECT_TRUE(result);
    EXPECT_DOUBLE_EQ(acc.getBalance(), 70.0);
}

TEST(AccountTest, WithdrawInsufficientFunds) {
    Account acc(1, 100.0);
    bool result = acc.withdraw(150.0);
    EXPECT_FALSE(result);
    EXPECT_DOUBLE_EQ(acc.getBalance(), 100.0);
}

TEST(AccountTest, WithdrawNegativeThrows) {
    Account acc(1, 100.0);
    EXPECT_THROW(acc.withdraw(-10.0), std::invalid_argument);
}
