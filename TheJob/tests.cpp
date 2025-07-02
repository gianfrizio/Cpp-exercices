#include <iostream>
#include "Account.hpp"

int main() {
    // Display initial account information (should be zero)
    Account::displayAccountsInfos();

    // Create some accounts with initial deposits
    Account acc1(1000);
    Account acc2(2000);
    Account acc3(500);

    // Display updated account information
    Account::displayAccountsInfos();

    // Make deposits
    acc1.makeDeposit(500);
    acc2.makeDeposit(300);
    acc3.makeDeposit(700);

    // Display individual account statuses
    acc1.displayStatus();
    acc2.displayStatus();
    acc3.displayStatus();

    // Make withdrawals
    acc1.makeWithdrawal(200);
    acc2.makeWithdrawal(5000); // should be refused
    acc3.makeWithdrawal(300);

    // Display updated global account information
    Account::displayAccountsInfos();

    // Display individual account statuses again
    acc1.displayStatus();
    acc2.displayStatus();
    acc3.displayStatus();

    return 0;
}
