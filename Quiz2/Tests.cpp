#include <iostream>
#include <exception>
using namespace std;

class BankAccount
{
    virtual int BankAccount::deposit(int amount) = 0;
    virtual int BankAccount::withdraw(int amount) = 0;

public:
    int balance;
    int transactionFee = 5;
    int getbalance()
    {
        return this->balance;
    }
};

class CheckingAccount : public BankAccount
{
    int transaction_fee(int curr_balance)
    {
        if (curr_balance <= 3000)
        {
            curr_balance - this->transactionFee;
        }
        return curr_balance;
    }

    int deposit(int curr_amount, int curr_balance)
    {
        if (this->balance < 3000)
        {
            this->balance = transaction_fee(this->balance);
        }
        this->balance = this->balance + curr_amount;
        return this->balance;
    }

    int retrieve(int retrieve_amount, int curr_balance)
    {
        notification(this->balance, retrieve_amount);
        if (this->balance < 3000)
        {
            this->balance = transaction_fee(this->balance);
        }
        this->balance = this->balance - curr_balance;
        return this->balance;
    }

    void notification(int balance, int retrieve)
    {
        try
        {
            if (this->balance - retrieve < 0)
            {
                throw "Cannot remove amount";
            }
        }
        catch (...)
        {
            cout << "Exception caught" << endl;
        }
    }
};

class SavingAccount : public BankAccount
{
    int deposit_large(int dep_amount)
    {
        if (dep_amount > 1000)
        {
            this->balance += this->balance * 0.03;
        }
    }

    void notification(int balance, int retrieve)
    {
        try
        {
            if (this->balance - retrieve < 0)
            {
                throw "Cannot remove amount";
            }
        }
        catch (...)
        {
            cout << "Exception caught" << endl;
        }
    }
}
