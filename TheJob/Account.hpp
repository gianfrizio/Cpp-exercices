#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

class Account {
private:
    static int _nbAccounts;
    static int _totalAmount;
    static int _totalNbDeposits;
    static int _totalNbWithdrawals;

    int _accountIndex;
    int _amount;
    int _nbDeposits;
    int _nbWithdrawals;

public:
    Account(int initial_deposit);
    ~Account();

    void makeDeposit(int deposit);
    bool makeWithdrawal(int withdrawal);

    int checkAmount() const;
    void displayStatus() const;

    static void displayAccountsInfos();
};

#endif
