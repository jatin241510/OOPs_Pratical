// Author: [Jatin 241510]
#include <iostream>
using namespace std;

/*
Class Name: Student
Purpose: Demonstrate static data member and static member function
Static member: count (tracks total objects created)
Static function: getCount() returns count without an object
*/

class Student {
    string name;
    int rollNo;
    static int count;   // static data member

public:
    Student(string n, int r) : name(n), rollNo(r) {
        count++;
        cout << "Student created: " << name << endl;
    }

    void display() {
        cout << "Name: " << name << ", Roll No: " << rollNo << endl;
    }

    // static member function
    static int getCount() {
        return count;
    }
};

int Student::count = 0; // definition outside class

int main() {
    cout << "Count before: " << Student::getCount() << endl;

    Student s1("Alice", 101);
    Student s2("Bob",   102);
    Student s3("Carol", 103);

    s1.display();
    s2.display();
    s3.display();

    cout << "Total Students: " << Student::getCount() << endl;
    return 0;
}
