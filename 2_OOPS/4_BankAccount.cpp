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
    float accountBalance;
public:
    BankAccount() : accountNumber(""), accountHolderName(""), accountType(""), accountBalance(0.0) {}
    void setAccountNumber (const std::string &accNum)
    {
        accountNumber = accNum;
    }
    void setAccountHolderName(const std::string &accName)
    {
        accountHolderName = accName;
    }
    void setAccountType(const std::string &accType)
    {
        accountType = accType;
    }
    void setAccountBalance(const float &accBalance)
    {
        accountBalance = accBalance;
    }

};

int main(){

  return 0;
}
