#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "banking/Account.hpp"
#include "banking/Transaction.hpp"

using namespace banking;
using ::testing::NiceMock;

class MockAccount : public Account {
public:
    MockAccount(int id, double balance): Account(id, balance) {}

    MOCK_METHOD(bool, withdraw, (double amount), (override));
    MOCK_METHOD(void, deposit, (double amount), (override));
};

TEST(TransactionTest, TransferSuccess) {
    NiceMock<MockAccount> from(1, 100.0);
    NiceMock<MockAccount> to(2, 0.0);

    EXPECT_CALL(from, withdraw(50.0)).WillOnce(::testing::Return(true));
    EXPECT_CALL(to, deposit(50.0)).Times(1);

    bool result = Transaction::transfer(from, to, 50.0);
    EXPECT_TRUE(result);
}

TEST(TransactionTest, TransferFailure) {
    NiceMock<MockAccount> from(1, 100.0);
    NiceMock<MockAccount> to(2, 0.0);

    EXPECT_CALL(from, withdraw(150.0)).WillOnce(::testing::Return(false));
    EXPECT_CALL(to, deposit(::testing::_)).Times(0);

    bool result = Transaction::transfer(from, to, 150.0);
    EXPECT_FALSE(result);
}
