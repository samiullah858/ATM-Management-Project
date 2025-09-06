#include <iostream>
#include <string>
using namespace std;

class User 
{
protected:
    string name;
    string accountNumber;
public:
    User(string n, string accNum) : name(n), accountNumber(accNum) {}
    void displayDetails() 
	{
        cout<<"User Name: "<<name<<endl;
        cout<<"Account Number: "<<accountNumber<<endl;
    }
};

class Transaction 
{
protected:
    float balance;
public:
    Transaction(float initialBalance = 0.0) : balance(initialBalance) {}
    void deposit(float amount) 
	{
        if (amount > 0) 
		{
            balance += amount;
            cout<<"Successfully deposited $"<<amount<<endl;
        } else 
		{
            cout<<"Invalid deposit amount"<<endl;
        }
    }
    bool withdraw(float amount) 
	{
        if (amount > 0 && amount <= balance) 
		{
            balance -= amount;
            cout<<"Successfully withdrew $"<<amount<<endl;
            return true;
        }
		 else 
		{
            cout<<"Invalid withdrawal amount or insufficient balance"<<endl;
        }
    }
    void checkBalance() 
	{
        cout<<"Current Balance: $"<<balance<<endl;
    }
};

class ATM : public User, public Transaction 
{
public:
    ATM(string n, string accNum, float initialBalance) 
        : User(n, accNum), Transaction(initialBalance) {}

    void showMenu() 
	{
        int choice;
        float amount;
        do {
            cout<<"\n=== ATM Menu ==="<<endl;
            cout<<"1. Display User Details"<<endl;
            cout<<"2. Deposit Money"<<endl;
            cout<<"3. Withdraw Money"<<endl;
            cout<<"4. Check Balance"<<endl;
            cout<<"5. Exit"<<endl;
            cout<<"Enter choice (1-5): ";
            cin>>choice;

            switch (choice) 
			{
                case 1:
                    displayDetails();
                    break;
                case 2:
                    cout<<"Enter amount to deposit: $";
                    cin>>amount;
                    deposit(amount);
                    break;
                case 3:
                    cout<<"Enter amount to withdraw: $";
                    cin>>amount;
                    withdraw(amount);
                    break;
                case 4:
                    checkBalance();
                    break;
                case 5:
                    cout<<"Thank you for using the ATM. Goodbye!"<<endl;
                    break;
                default:
                    cout<<"Invalid choice. Please try again."<<endl;
            }
        } while (choice != 5);
    }
};

int main() 
{
    ATM atm("John Doe", "1234567890", 1000.0);
    
    cout<<"Welcome to the ATM Management System"<<endl;
    atm.showMenu();
}
