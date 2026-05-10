// Author: [Jatin 241510]
#include <iostream>
using namespace std;

/*
Class Name: Complex
Purpose: Overload +, -, ++, ==, and << for complex numbers
*/

class Complex {
public:
    float real, imag;

    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    // Overload +
    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    // Overload -
    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    // Overload ++ (prefix)
    Complex operator++() {
        ++real; ++imag;
        return *this;
    }

    // Overload ==
    bool operator==(const Complex& c) const {
        return (real == c.real && imag == c.imag);
    }

    // Overload << (friend function)
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }
};

int main() {
    Complex c1(3.0f, 4.0f), c2(1.0f, 2.0f);

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c1 + c2 = " << (c1 + c2) << endl;
    cout << "c1 - c2 = " << (c1 - c2) << endl;
    ++c1;
    cout << "++c1    = " << c1 << endl;
    cout << "c1 == c2: " << (c1 == c2 ? "Yes" : "No") << endl;
    return 0;
}
