/*
Bank Account
Create a class called "BankAccount" that represents a bank account with the following attributes and methods:

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
Overload the "+" operator to add two BankAccount objects together. The result should be a new BankAccount object with the account balance
of the two accounts added together.
Overload the "==" operator to compare two BankAccount objects based on their account number.
Virtual method "getInterestRate" that returns an interest rate for the account type. This method should be overridden by child classes to
implement different interest rates for different account types.
Create two child classes of BankAccount called "SavingsAccount" and "CheckingAccount" with different interest rates for each account type.

In the main function, create several BankAccount, SavingsAccount, and CheckingAccount objects, and perform the following operations:

Deposit and withdraw funds from the accounts.
Add two BankAccount objects together using the overloaded "+" operator.
Compare two BankAccount objects using the overloaded "==" operator.
Call the "getInterestRate" method on the child objects to get the interest rate for each account type.
*/
#include <iostream>

class BankAccount
{
protected:
    std::string accountNumber;
    std::string accountHolderName;
    std::string accountType;
    double accountBalance;

public:
    BankAccount(const std::string &accNumber, const std::string &accHolderName, const std::string &accType, float accBalance)
        : accountNumber(accNumber), accountHolderName(accHolderName), accountType(accType), accountBalance(accBalance) {}

    void setAccountNumber(const std::string &accNumber)
    {
        accountNumber = accNumber;
    }
    void setAccountHolderName(const std::string &accHolderName)
    {
        accountHolderName = accHolderName;
    }
    void setAccountType(const std::string &accType)
    {
        accountType = accType;
    }
    void setAccountBalance(const float &accBalance)
    {
        accountBalance = accBalance;
    }
    std::string getAccountNumber() const
    {
        return accountNumber;
    }
    std::string getAccountHolderName() const
    {
        return accountHolderName;
    }
    std::string getAccountType() const
    {
        return accountType;
    }
    double getAccountBalance() const
    {
        return accountBalance;
    }
    void deposit(double amount)
    {
        accountBalance += amount;
        std::cout << "Amount Deposited: " << amount << std::endl;
    }
    void withdraw(double amount)
    {
        if (amount > accountBalance)
            std::cout << "Account balance insufficient" << std::endl;
        else
        {
            accountBalance -= amount;
            std::cout << "Amount Withdrawn" << std::endl;
        }
    }
    virtual float getInterestRate() const
    {
        return 0.03 * accountBalance;
    }
    // Overload the + operator to add two BankAccount objects together
    BankAccount operator+(const BankAccount &other) const
    {
        return BankAccount("MergedAccount", "MergedAccount", "MergedAccount", accountBalance + other.accountBalance);
    }

    // Overload the == operator to compare two BankAccount objects based on their account number
    bool operator==(const BankAccount &other) const
    {
        return accountNumber == other.accountNumber;
    }
};

class SavingsAccount : public BankAccount
{
public:
    SavingsAccount(const std::string &accNumber, const std::string &accHolderName, const std::string &accType, float accBalance)
        : BankAccount(accNumber, accHolderName, "Savings", accBalance) {}

    // Override the getInterestRate method for SavingsAccount
    float getInterestRate() const override 
    {
        return 3.0; // Example interest rate for SavingsAccount (3%)
    }

};

class CheckingAccount : public BankAccount
{
public:
    CheckingAccount(const std::string &accNumber, const std::string &accHolderName, const std::string &accType, float accBalance)
        : BankAccount(accNumber, accHolderName, "Savings", accBalance) {}

    // Override the getInterestRate method for SavingsAccount
    float getInterestRate() const override 
    {
        return 0.5; // Example interest rate for SavingsAccount (3%)
    }

};

int main()
{
    // Create BankAccount objects
    BankAccount acc1("12345", "Alice", "Savings", 1000.0);
    BankAccount acc2("67890", "Bob", "Checking", 2000.0);
    double amount = 0.0;
    std::cout << "Enter amount to deposit: " << std::endl;
    std::cin >> amount;
    acc1.deposit(amount);
    std::cout << "Enter amount to withdraw: " << std::endl;
    std::cin >> amount;
    acc1.withdraw(amount);
    return 0;
}
