// Author: [Jatin 241510]
#include <iostream>
using namespace std;

/*
Abstract Base Class: Shape
Pure virtual functions: area(), perimeter(), draw()
Derived classes: Circle, Rectangle, Triangle
*/

class Shape {
public:
    // Pure virtual functions make Shape an abstract class
    virtual float area()      const = 0;
    virtual float perimeter() const = 0;
    virtual void  draw()      const = 0;

    // Virtual destructor
    virtual ~Shape() {}
};

class Circle : public Shape {
    float radius;
public:
    Circle(float r) : radius(r) {}

    float area()      const override { return 3.14159f * radius * radius; }
    float perimeter() const override { return 2 * 3.14159f * radius; }
    void  draw()      const override {
        cout << "Drawing Circle (r=" << radius << ")" << endl;
    }
};

class Rectangle : public Shape {
    float length, width;
public:
    Rectangle(float l, float w) : length(l), width(w) {}

    float area()      const override { return length * width; }
    float perimeter() const override { return 2 * (length + width); }
    void  draw()      const override {
        cout << "Drawing Rectangle (" << length << "x" << width << ")" << endl;
    }
};

class Triangle : public Shape {
    float a, b, c;
public:
    Triangle(float x, float y, float z) : a(x), b(y), c(z) {}

    float perimeter() const override { return a + b + c; }
    float area()      const override {
        float s = perimeter() / 2;
        return sqrt(s * (s-a) * (s-b) * (s-c));
    }
    void  draw()      const override {
        cout << "Drawing Triangle (sides=" << a << "," << b << "," << c << ")" << endl;
    }
};

int main() {
    Shape* shapes[] = {
        new Circle(5.0f),
        new Rectangle(4.0f, 6.0f),
        new Triangle(3.0f, 4.0f, 5.0f)
    };

    for (auto* s : shapes) {
        s->draw();
        cout << "  Area      = " << s->area()      << endl;
        cout << "  Perimeter = " << s->perimeter() << endl;
        delete s;
    }
    return 0;
}
