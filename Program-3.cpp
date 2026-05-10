// Author: [Jatin 241510]
#include <iostream>
using namespace std;

/*
Purpose: Demonstrate function overloading
Overloaded functions: area() for circle/rectangle/triangle
                      sum()  for 2 and 3 integers
                      volume() for cube/cuboid/cylinder
*/

// Area overloads
float area(float r)                   { return 3.14159f * r * r; }
float area(float l, float b)          { return l * b; }
float area(float b, float h, int tri) { return 0.5f * b * h; }

// Sum overloads
int sum(int a, int b)          { return a + b; }
int sum(int a, int b, int c)   { return a + b + c; }

// Volume overloads
float volume(float side)                 { return side * side * side; }
float volume(float l, float b, float h) { return l * b * h; }
float volume(float r, float h, int cyl) { return 3.14159f * r * r * h; }

int main() {
    cout << "Area" << endl;
    cout << "Circle (r=7)         : " << area(7.0f)          << endl;
    cout << "Rectangle (5x3)      : " << area(5.0f, 3.0f)    << endl;
    cout << "Triangle (b=6, h=4)  : " << area(6.0f, 4.0f, 1) << endl;

    cout << "\nSum" << endl;
    cout << "Sum of 2 numbers (3,4)   : " << sum(3, 4)    << endl;
    cout << "Sum of 3 numbers (1,2,3) : " << sum(1, 2, 3) << endl;

    cout << "\nVolume" << endl;
    cout << "Cube (side=3)        : " << volume(3.0f)              << endl;
    cout << "Cuboid (2x3x4)       : " << volume(2.0f, 3.0f, 4.0f) << endl;
    cout << "Cylinder (r=3, h=5)  : " << volume(3.0f, 5.0f, 1)    << endl;
    return 0;
}

