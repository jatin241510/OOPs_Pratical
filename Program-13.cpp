// Author: [Jatin 241510]
#include <iostream>
#include <vector>
using namespace std;

/*
Class Name: BankAccount
Purpose: Core account class with deposit, withdraw, and display
*/
class BankAccount {
protected:
    int    accountNo;
    string holderName;
    double balance;

public:
    BankAccount(int no, string name, double bal)
        : accountNo(no), holderName(name), balance(bal) {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited Rs " << amount << ". New balance: Rs " << balance << endl;
    }

    virtual void withdraw(double amount) {
        if (amount > balance) { cout << "Insufficient funds!" << endl; return; }
        balance -= amount;
        cout << "Withdrawn Rs " << amount << ". New balance: Rs " << balance << endl;
    }

    virtual void display() const {
        cout << "Acc No : " << accountNo   << endl;
        cout << "Name   : " << holderName  << endl;
        cout << "Balance: Rs " << balance  << endl;
    }

    int getAccountNo() const { return accountNo; }
    virtual ~BankAccount() {}
};

// Savings account: earns interest
class SavingsAccount : public BankAccount {
    float interestRate;
public:
    SavingsAccount(int no, string name, double bal, float rate)
        : BankAccount(no, name, bal), interestRate(rate) {}

    void addInterest() {
        double interest = balance * interestRate / 100.0;
        balance += interest;
        cout << "Interest Rs " << interest << " added. Balance: Rs " << balance << endl;
    }

    void display() const override {
        BankAccount::display();
        cout << "Type   : Savings (Rate=" << interestRate << "%)" << endl;
    }
};

// Current account: overdraft limit
class CurrentAccount : public BankAccount {
    double overdraftLimit;
public:
    CurrentAccount(int no, string name, double bal, double limit)
        : BankAccount(no, name, bal), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (amount > balance + overdraftLimit) {
            cout << "Exceeds overdraft limit!" << endl; return;
        }
        balance -= amount;
        cout << "Withdrawn Rs " << amount << ". Balance: Rs " << balance << endl;
    }

    void display() const override {
        BankAccount::display();
        cout << "Type   : Current (Overdraft=Rs " << overdraftLimit << ")" << endl;
    }
};

// Bank manages multiple accounts
class Bank {
    vector<BankAccount*> accounts;
    int nextAccNo = 1001;

public:
    void createSavings(string name, double bal, float rate) {
        accounts.push_back(new SavingsAccount(nextAccNo++, name, bal, rate));
        cout << "Savings account created: " << nextAccNo - 1 << endl;
    }

    void createCurrent(string name, double bal, double limit) {
        accounts.push_back(new CurrentAccount(nextAccNo++, name, bal, limit));
        cout << "Current account created: " << nextAccNo - 1 << endl;
    }

    BankAccount* find(int accNo) {
        for (auto* a : accounts)
            if (a->getAccountNo() == accNo) return a;
        return nullptr;
    }

    void listAll() {
        cout << "\nAll Accounts" << endl;
        for (auto* a : accounts) { a->display(); cout << "---" << endl; }
    }

    ~Bank() { for (auto* a : accounts) delete a; }
};

int main() {
    Bank bank;
    int choice, accNo;
    double amount;
    string name;

    do {
        cout << "\nBank Management System" << endl;
        cout << "1. Create Savings Account" << endl;
        cout << "2. Create Current Account" << endl;
        cout << "3. Deposit"               << endl;
        cout << "4. Withdraw"              << endl;
        cout << "5. Display All Accounts"  << endl;
        cout << "0. Exit"                  << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Name: "; cin >> name;
                cout << "Initial balance: "; cin >> amount;
                bank.createSavings(name, amount, 4.5f);
                break;
            case 2:
                cout << "Name: "; cin >> name;
                cout << "Initial balance: "; cin >> amount;
                bank.createCurrent(name, amount, 10000);
                break;
            case 3:
                cout << "Account No: "; cin >> accNo;
                cout << "Amount: ";     cin >> amount;
                if (auto* a = bank.find(accNo)) a->deposit(amount);
                else cout << "Account not found!" << endl;
                break;
            case 4:
                cout << "Account No: "; cin >> accNo;
                cout << "Amount: ";     cin >> amount;
                if (auto* a = bank.find(accNo)) a->withdraw(amount);
                else cout << "Account not found!" << endl;
                break;
            case 5:
                bank.listAll();
                break;
            case 0:
                cout << "Thank you for using Bank Management System!" << endl;
                break;
            default:
                cout << "Invalid option." << endl;
        }
    } while (choice != 0);

    return 0;
}
