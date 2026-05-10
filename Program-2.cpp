// Author: [Jatin 241510]
#include <iostream>
using namespace std;

/*
Function Name: simpleInterest
Purpose: Calculate Simple Interest using default arguments
Args:
 - float principal: Principal amount
 - float rate     : Rate of interest (default = 5.0)
 - int   time     : Time in years   (default = 1)
Return Type: float
*/

float simpleInterest(float principal, float rate = 5.0, int time = 1) {
    return (principal * rate * time) / 100.0;
}

int main() {
    float p;
    cout << "Enter Principal: ";
    cin >> p;

    cout << "SI (default rate=5%, time=1yr) : " << simpleInterest(p)        << endl;
    cout << "SI (rate=8%, default time=1yr) : " << simpleInterest(p, 8.0)   << endl;
    cout << "SI (rate=10%, time=3yrs)       : " << simpleInterest(p, 10.0, 3) << endl;
    return 0;
}

