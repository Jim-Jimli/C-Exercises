/*
Write a program to find smallest of three numbers.
*/

#include <iostream>
#include <map>
using namespace std;

int main() {

    int a, b, c,i;
    string z;

    cout << "Enter A value: " ;
    cin >> a;

    cout << "Enter B value: ";
    cin >> b;
    if (a<b) {
        z = "A";
        i = a;
    }
    else {
        z = "B";
        i = b;
    }

    cout << "Enter C value: ";
    cin >> c;
    if ( c == i )
    {
        z += " and C";
    }
     else if (c<i)
    {
        z = "C";
    }

    cout << z << " is the smallest" << endl;
    return 0;
}