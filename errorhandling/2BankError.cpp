#include <iostream>
#include <stdexcept>
using namespace std;

class InsufficientFundsException : public runtime_error
{
public:
    InsufficientFundsException(double amount, double balance) : runtime_error("Insufficient funds"),
                                                                requested_amount(amount), account_balance(balance) {}

    double get_requested_amount() const { return requested_amount; }
    double get_account_balance() const { return account_balance; }

private:
    double requested_amount;
    double account_balance;
};

int main()
{
    double balance = 1000.0;
    double amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;

    try
    {
        if (amount > balance)
        {
            throw InsufficientFundsException(amount, balance);
        }
        else
        {
            balance -= amount;
            cout << "New balance: " << balance << endl;
        }
    }
    catch (const InsufficientFundsException &e)
    {
        cerr << "Error: " << e.what() << endl;
        cerr << "Requested amount: " << e.get_requested_amount() << endl;
        cerr << "Account balance: " << e.get_account_balance() << endl;
    }

    return 0;
}
