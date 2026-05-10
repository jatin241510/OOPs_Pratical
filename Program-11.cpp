// Author: [Jatin 241510]
#include <iostream>
using namespace std;

/*
Purpose: Demonstrate Containership (Composition)
Car HAS-A Engine, Wheels, FuelTank
*/

class Engine {
    int horsepower;
    string type;
public:
    Engine(int hp, string t) : horsepower(hp), type(t) {}
    void display() const {
        cout << "  Engine : " << type << ", " << horsepower << " HP" << endl;
    }
};

class FuelTank {
    float capacity; // litres
public:
    FuelTank(float c) : capacity(c) {}
    void display() const {
        cout << "  Tank   : " << capacity << " litres" << endl;
    }
};

class Wheels {
    int count;
    int size; // inches
public:
    Wheels(int c, int s) : count(c), size(s) {}
    void display() const {
        cout << "  Wheels : " << count << " x " << size << '"' << endl;
    }
};

// Car CONTAINS Engine, FuelTank, Wheels (Composition)
class Car {
    string brand;
    Engine    engine;
    FuelTank  tank;
    Wheels    wheels;

public:
    Car(string b, int hp, string eType, float tankCap, int wCount, int wSize)
        : brand(b), engine(hp, eType), tank(tankCap), wheels(wCount, wSize) {}

    void display() const {
        cout << "Car: " << brand << endl;
        engine.display();
        tank.display();
        wheels.display();
    }

    void start() const {
        cout << brand << " started. Engine running!" << endl;
    }
};

int main() {
    Car myCar("Toyota Camry", 203, "V4 Petrol", 60.0f, 4, 17);
    myCar.display();
    myCar.start();

    Car sportsCar("BMW M3", 503, "V6 Turbo", 59.0f, 4, 19);
    sportsCar.display();
    sportsCar.start();
    return 0;
}

