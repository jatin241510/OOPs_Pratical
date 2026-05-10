// Author: [Jatin 241510]
#include <iostream>
using namespace std;

/*
Purpose: Menu-driven Currency Converter (base currency: INR)
Conversion rates (approximate):
  1 USD = 83.5 INR
  1 EUR = 90.2 INR
  1 GBP = 105.3 INR
  1 JPY = 0.56 INR
*/

class CurrencyConverter {
    const float USD_RATE = 83.5f;
    const float EUR_RATE = 90.2f;
    const float GBP_RATE = 105.3f;
    const float JPY_RATE = 0.56f;

public:
    void convertFromINR(float amount) {
        cout << "\nINR " << amount << " = " << endl;
        cout << "  USD : " << amount / USD_RATE << endl;
        cout << "  EUR : " << amount / EUR_RATE << endl;
        cout << "  GBP : " << amount / GBP_RATE << endl;
        cout << "  JPY : " << amount / JPY_RATE << endl;
    }

    void convertToINR(int choice, float amount) {
        float inr = 0;
        string currency;
        switch(choice) {
            case 1: inr = amount * USD_RATE; currency = "USD"; break;
            case 2: inr = amount * EUR_RATE; currency = "EUR"; break;
            case 3: inr = amount * GBP_RATE; currency = "GBP"; break;
            case 4: inr = amount * JPY_RATE; currency = "JPY"; break;
        }
        cout << currency << " " << amount << " = INR " << inr << endl;
    }
};

int main() {
    CurrencyConverter cc;
    int choice;
    float amount;

    do {
        cout << "\nCurrency Converter" << endl;
        cout << "1. INR to All Currencies" << endl;
        cout << "2. USD to INR"            << endl;
        cout << "3. EUR to INR"            << endl;
        cout << "4. GBP to INR"            << endl;
        cout << "5. JPY to INR"            << endl;
        cout << "0. Exit"                  << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0) break;

        cout << "Enter amount: ";
        cin >> amount;

        if (choice == 1)       cc.convertFromINR(amount);
        else if (choice <= 5)  cc.convertToINR(choice - 1, amount);
        else                   cout << "Invalid choice!" << endl;

    } while (choice != 0);

    cout << "Exiting converter. Goodbye!" << endl;
    return 0;
}
