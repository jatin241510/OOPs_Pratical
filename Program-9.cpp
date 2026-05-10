// Author: [Jatin 241510]
#include <iostream>
using namespace std;

/*
Purpose: Demonstrate function overriding and runtime polymorphism
Base class: Employee  (virtual function: calculateSalary)
Derived   : Manager, Developer
*/

class Employee {
protected:
    string name;
    float baseSalary;

public:
    Employee(string n, float s) : name(n), baseSalary(s) {}

    // Virtual function - overridden in derived classes
    virtual void calculateSalary() {
        cout << name << " | Base Salary: Rs " << baseSalary << endl;
    }

    virtual ~Employee() {}
};

class Manager : public Employee {
    float bonus;
public:
    Manager(string n, float s, float b) : Employee(n, s), bonus(b) {}

    void calculateSalary() override {
        cout << name << " [Manager] | Total: Rs "
             << (baseSalary + bonus)
             << " (Base=" << baseSalary << " + Bonus=" << bonus << ")" << endl;
    }
};

class Developer : public Employee {
    int overtimeHours;
public:
    Developer(string n, float s, int hrs) : Employee(n, s), overtimeHours(hrs) {}

    void calculateSalary() override {
        float total = baseSalary + overtimeHours * 200.0f;
        cout << name << " [Developer] | Total: Rs "
             << total << " (Base=" << baseSalary
             << " + OT=" << overtimeHours * 200.0f << ")" << endl;
    }
};

int main() {
    Employee* emp[3];
    emp[0] = new Employee("Alice", 30000);
    emp[1] = new Manager("Bob", 50000, 15000);
    emp[2] = new Developer("Carol", 40000, 10);

    cout << "Payroll (Runtime Polymorphism)" << endl;
    for (int i = 0; i < 3; i++)
        emp[i]->calculateSalary();

    for (int i = 0; i < 3; i++) delete emp[i];
    return 0;
}
