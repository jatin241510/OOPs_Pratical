// Author: [Jatin 241510]
#include <iostream>
using namespace std;

/*
Class Name: Rectangle
Purpose: Demonstrate all four types of constructors
Constructors:
  - Default         : sets length=0, width=0
  - Parameterized   : sets given length and width
  - Copy            : copies from another Rectangle
  - Overloaded      : sets square (length=width=side)
*/

class Rectangle {
    float length, width;

public:
    // Default constructor
    Rectangle() : length(0), width(0) {
        cout << "Default Constructor called." << endl;
    }

    // Parameterized constructor
    Rectangle(float l, float w) : length(l), width(w) {
        cout << "Parameterized Constructor called." << endl;
    }

    // Copy constructor
    Rectangle(const Rectangle& r) : length(r.length), width(r.width) {
        cout << "Copy Constructor called." << endl;
    }

    // Overloaded constructor (square)
    Rectangle(float side) : length(side), width(side) {
        cout << "Overloaded (Square) Constructor called." << endl;
    }

    void display() {
        cout << "Length=" << length << " Width=" << width
             << " Area=" << length * width << endl;
    }
};

int main() {
    Rectangle r1;               // Default
    r1.display();

    Rectangle r2(5.0f, 3.0f);  // Parameterized
    r2.display();

    Rectangle r3(r2);           // Copy
    r3.display();

    Rectangle r4(4.0f);         // Overloaded (square)
    r4.display();
    return 0;
}
