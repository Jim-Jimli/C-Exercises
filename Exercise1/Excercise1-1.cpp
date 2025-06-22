/*
Evaluate the expression: Z = ax +(b-c)(c-d)/y
*/

#include <iostream>
using namespace std;

int main() {

    cout << " Z = ax +(b-c)(c-d)/y " << endl;

    int a,b,c,d,x,y;
    long z;

    cout << "Enter a value: " ;
    cin >> a;
    
    cout << "Enter b value: ";
    cin >> b;

    cout << "Enter c value: ";
    cin >> c;

    cout << "Enter d value: ";
    cin >> d;

    cout << "Enter x value: ";   
    cin >> x;

    cout << "Enter y value: ";
    cin >> y;

    z = a*x + (b - c)*(c - d) / y;

    cout << "Z = " << z << endl;
    return 0;
}