// Author: [Jatin 241510]
#include <iostream>
using namespace std;

/*
Class Name: BankAccount
Purpose: Dynamic initialization - values assigned at runtime via constructor
The constructor accepts user-provided values at object creation time
*/

class BankAccount {
    string holderName;
    int accountNo;
    double balance;

public:
    // Constructor with dynamic (runtime) initialization
    BankAccount(string name, int accNo, double bal) {
        holderName = name;
        accountNo  = accNo;
        balance    = bal;
        cout << "Account created dynamically." << endl;
    }

    void display() {
        cout << "Holder : " << holderName << endl;
        cout << "Acc No : " << accountNo  << endl;
        cout << "Balance: Rs " << balance  << endl;
    }
};

int main() {
    string name;
    int accNo;
    double bal;

    cout << "Enter holder name, account number, and balance: ";
    cin >> name >> accNo >> bal;

    // Object initialized dynamically with runtime data
    BankAccount acc(name, accNo, bal);
    acc.display();
    return 0;
}
