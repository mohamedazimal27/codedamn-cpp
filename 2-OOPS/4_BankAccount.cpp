/*
Bank Account
Create a class called BankAccount that represents a bank account with the following attributes and methods:

Attributes:
Account number (string)
Account holder name (string)
Account type (string)
Account balance (float)
Methods:
Constructor: Initializes the account number, account holder name, account type, and account balance.
Setter and Getter methods for each attribute: These methods should enforce data encapsulation by making the attributes private 
and providing public getter and setter methods to access and set the attribute values.
Deposit method: Adds a specified amount to the account balance.
Withdraw method: Subtracts a specified amount from the account balance. If the withdrawal amount is greater than the account balance, 
it should print an error message and not perform the withdrawal.
Overload the + operator to add two BankAccount objects together. The result should be a new BankAccount object with the account balance of 
the two accounts added together.
Overload the == operator to compare two BankAccount objects based on their account number.
Virtual method getInterestRate that returns an interest rate for the account type. This method should be overridden by child classes to implement 
different interest rates for different account types.
Create two child classes of BankAccount called SavingsAccount and CheckingAccount with different interest rates for each account type.

In the main function, create several BankAccount, SavingsAccount, and CheckingAccount objects, and perform the following operations:

Deposit and withdraw funds from the accounts.
Add two BankAccount objects together using the overloaded + operator.
Compare two BankAccount objects using the overloaded == operator.
Call the getInterestRate method on the child objects to get the interest rate for each account type.
*/


#include <iostream>
#include <string>
#include <cmath> // for pow function

class BankAccount
{
private:
    std::string accountNumber;
    std::string accountHolder;
    float balance;
    std::string *transactionHistory;
    int transactionCount;

public:
    const int maxTransactions = 100;
    BankAccount(const std::string &accNumber, const std::string &accHolder, float initialBalance, int maxTrans = 100)
        : accountNumber(accNumber), accountHolder(accHolder), balance(initialBalance), maxTransactions(maxTrans)
    {
        transactionHistory = new std::string[maxTransactions];
        transactionCount = 0;
    }

    ~BankAccount()
    {
        delete[] transactionHistory;
    }

    std::string getAccountNumber() const
    {
        return accountNumber;
    }

    std::string getAccountHolder() const
    {
        return accountHolder;
    }

    float getBalance() const
    {
        return balance;
    }

    void deposit(float amount)
    {
        if (amount > 0)
        {
            balance += amount;
            recordTransaction("Deposit: $" + std::to_string(amount));
            std::cout << "Deposited $" << amount << " into account " << accountNumber << "\n";
        }
        else
        {
            std::cout << "Invalid deposit amount. Amount must be greater than zero.\n";
        }
    }

    void withdraw(float amount)
    {
        if (amount > 0)
        {
            if (amount <= balance)
            {
                balance -= amount;
                recordTransaction("Withdrawal: $" + std::to_string(amount));
                std::cout << "Withdrawn $" << amount << " from account " << accountNumber << "\n";
            }
            else
            {
                std::cout << "Insufficient balance to withdraw $" << amount << " from account " << accountNumber << "\n";
            }
        }
        else
        {
            std::cout << "Invalid withdrawal amount. Amount must be greater than zero.\n";
        }
    }

    void displayTransactionHistory() const
    {
        std::cout << "Transaction History for Account: " << accountNumber << "\n";
        for (int i = 0; i < transactionCount; ++i)
        {
            std::cout << transactionHistory[i] << "\n";
        }
    }

    // Overload the + operator to add two BankAccount objects
    BankAccount operator+(const BankAccount &other) const
    {
        // Create a new BankAccount with the sum of balances
        return BankAccount("MergedAccount", "MergedAccount", balance + other.balance);
    }

    // Overload the == operator to compare two BankAccount objects based on their account number
    bool operator==(const BankAccount &other) const
    {
        return accountNumber == other.accountNumber;
    }

protected:
    void recordTransaction(const std::string &transaction)
    {
        if (transactionCount < maxTransactions)
        {
            transactionHistory[transactionCount] = transaction;
            transactionCount++;
        }
    }
};

class CreditAccount : public BankAccount
{
private:
    float interestRate;

public:
    CreditAccount(const std::string &accNumber, const std::string &accHolder, float initialCreditLimit, float intRate)
        : BankAccount(accNumber, accHolder, -initialCreditLimit), interestRate(intRate) {}

    void chargeInterest()
    {
        if (getBalance() < 0)
        {
            float interest = -getBalance() * interestRate / 100;
            deposit(interest);
            recordTransaction("Interest Charged: $" + std::to_string(interest));
            std::cout << "Interest charged: $" << interest << " to account " << getAccountNumber() << "\n";
        }
    }
};

class JointAccount : public BankAccount
{
private:
    std::string *accountHolders;
    int numAccountHolders;

public:
    JointAccount(const std::string &accNumber, const std::string &primaryAccHolder, float initialBalance, int maxHolders = 5)
        : BankAccount(accNumber, primaryAccHolder, initialBalance), numAccountHolders(1)
    {
        accountHolders = new std::string[maxHolders];
        accountHolders[0] = primaryAccHolder;
    }

    ~JointAccount()
    {
        delete[] accountHolders;
    }

    void addAccountHolder(const std::string &accHolder)
    {
        if (numAccountHolders < maxTransactions)
        {
            accountHolders[numAccountHolders] = accHolder;
            numAccountHolders++;
        }
    }

    void displayAccountHolders() const
    {
        std::cout << "Account Holders for Account: " << getAccountNumber() << "\n";
        for (int i = 0; i < numAccountHolders; ++i)
        {
            std::cout << accountHolders[i] << "\n";
        }
    }
};

class SavingsAccount : public BankAccount
{
private:
    float interestRate;
    int compoundingFrequency; // Number of times interest is compounded per year

public:
    SavingsAccount(const std::string &accNumber, const std::string &accHolder, float initialBalance, float intRate, int compFreq)
        : BankAccount(accNumber, accHolder, initialBalance), interestRate(intRate), compoundingFrequency(compFreq) {}

    void calculateInterest()
    {
        float rate = interestRate / 100;
        float compoundFactor = 1 + (rate / compoundingFrequency);
        float newBalance = getBalance() * std::pow(compoundFactor, compoundingFrequency);
        float interestEarned = newBalance - getBalance();
        deposit(interestEarned);
        recordTransaction("Interest Earned: $" + std::to_string(interestEarned));
        std::cout << "Interest earned: $" << interestEarned << " in account " << getAccountNumber() << "\n";
    }
};

int main()
{
    // Create BankAccount objects
    BankAccount acc1("12345", "Alice", 1000.0);
    BankAccount acc2("67890", "Bob", 2000.0);

    // Deposit and withdraw funds
    acc1.deposit(500.0);
    acc2.withdraw(1000.0);

    // Add two BankAccount objects using the overloaded + operator
    BankAccount mergedAccount = acc1 + acc2;
    std::cout << "Merged Account Balance: $" << mergedAccount.getBalance() << "\n";

    // Compare two BankAccount objects using the overloaded == operator
    if (acc1 == acc2)
    {
        std::cout << "Account 1 and Account 2 have the same account number.\n";
    }
    else
    {
        std::cout << "Account 1 and Account 2 have different account numbers.\n";
    }

    // Create CreditAccount and JointAccount objects
    CreditAccount creditAcc("13579", "Eve", 5000.0, 5.0);
    JointAccount jointAcc("24680", "Charlie", 3000.0);

    // Charge interest for CreditAccount
    creditAcc.chargeInterest();

    // Add account holders to JointAccount
    jointAcc.addAccountHolder("David");
    jointAcc.addAccountHolder("Emily");

    // Create SavingsAccount object
    SavingsAccount savingsAcc("98765", "Frank", 8000.0, 4.0, 12);

    // Calculate interest for SavingsAccount
    savingsAcc.calculateInterest();

    // Display transaction history for accounts
    acc1.displayTransactionHistory();
    creditAcc.displayTransactionHistory();
    jointAcc.displayTransactionHistory();
    savingsAcc.displayTransactionHistory();

    // Display account holders for JointAccount
    jointAcc.displayAccountHolders();

    return 0;
}
