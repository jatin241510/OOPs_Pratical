// Author: [Jatin 241510]
#include <iostream>
using namespace std;

// Single Inheritance 
class Animal {
public:
    void breathe() { cout << "[Single] Animal breathes." << endl; }
};
class Dog : public Animal {
public:
    void bark() { cout << "[Single] Dog barks." << endl; }
};

// Multiple Inheritance 
class Father { public: void trait1() { cout << "[Multiple] Father's trait." << endl; } };
class Mother { public: void trait2() { cout << "[Multiple] Mother's trait." << endl; } };
class Child : public Father, public Mother {
public:
    void ownTrait() { cout << "[Multiple] Child's own trait." << endl; }
};

// Multilevel Inheritance
class GrandParent {
public:
    void gp() { cout << "[Multilevel] GrandParent." << endl; }
};
class Parent : public GrandParent {
public:
    void p() { cout << "[Multilevel] Parent." << endl; }
};
class GrandChild : public Parent {
public:
    void gc() { cout << "[Multilevel] GrandChild." << endl; }
};

// Hierarchical Inheritance
class Shape {
public:
    void draw() { cout << "[Hierarchical] Shape drawn." << endl; }
};
class Circle  : public Shape { public: void info() { cout << "Circle" << endl; } };
class Square  : public Shape { public: void info() { cout << "Square" << endl; } };

// Hybrid Inheritance
class A     { public: void show()  { cout << "[Hybrid] Class A." << endl; } };
class B : virtual public A { public: void showB() { cout << "[Hybrid] Class B." << endl; } };
class C : virtual public A { public: void showC() { cout << "[Hybrid] Class C." << endl; } };
class D : public B, public C { public: void showD() { cout << "[Hybrid] Class D." << endl; } };

int main() {
    Dog d; d.breathe(); d.bark();

    Child ch; ch.trait1(); ch.trait2(); ch.ownTrait();

    GrandChild gc; gc.gp(); gc.p(); gc.gc();

    Circle ci; ci.draw(); ci.info();
    Square sq; sq.draw(); sq.info();

    D hybrid; hybrid.show(); hybrid.showB(); hybrid.showC(); hybrid.showD();
    return 0;
}
