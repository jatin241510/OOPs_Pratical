// Author: [Jatin 241510]
#include <iostream>
using namespace std;

/*
Purpose: Demonstrate inline functions for arithmetic operations
Inline functions: add, subtract, multiply, divide
*/

inline int add(int a, int b)      { return a + b; }
inline int subtract(int a, int b) { return a - b; }
inline int multiply(int a, int b) { return a * b; }
inline float divide(float a, float b) {
    if (b == 0) { cout << "Division by zero!" << endl; return 0; }
    return a / b;
}

int main() {
    int x, y;
    cout << "Enter two integers: ";
    cin >> x >> y;

    cout << "Addition      : " << add(x, y)      << endl;
    cout << "Subtraction   : " << subtract(x, y) << endl;
    cout << "Multiplication: " << multiply(x, y) << endl;
    cout << "Division      : " << divide(x, y)   << endl;
    return 0;
}
