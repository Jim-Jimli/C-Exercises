/*
2. Write a program to create manipulation package. Allow the package to manage addition, subtraction, 
    multiplication and division classes.
    • Each class must have constructors with different argument list
    • For Eg. Addition (int, int), addition (double, double), addition (double, double, double)
    • Import your package and allow the user to manipulate their data.
*/

#include <iostream>
#include "math_operations.h"

using namespace MathOperations;
using namespace std;

int main() {
    try {
        Addition add1(8, 4);
        Addition add2(2.8, 3.89);
        Addition add3(11.2, 13.4, 15.6);
        Addition add4(5, 3.2);
        
        cout << "Addtion:" << endl;
        cout << " 8 + 4 = " << add1.getResult() << endl;
        cout << " 2.8 + 3.89 = " << add2.getResult() << endl;
        cout << " 11.2 + 13.4 + 15.6 = " << add3.getResult() << endl;
        cout << " 5 + 3.2 = " << add4.getResult() << endl;
        cout << endl;
        
        Subtraction sub1(10, 4);
        Subtraction sub2(5.5, 2.3);
        Subtraction sub3(10, 3.5);
        
        cout << "Substraction:" << endl;
        cout << "10 - 4 = " << sub1.getResult() << endl;
        cout << "5.5 - 2.3 = " << sub2.getResult() << endl;
        cout << "10 - 3.5 = " << sub3.getResult() << endl;
        cout << endl;
        
        Multiplication mul1(3, 4);
        Multiplication mul2(2.5, 4.5);
        Multiplication mul3(1.5, 2.5, 3.5);
        Multiplication mul4(3, 2.7);
        
        cout << "Multiplication:" << endl;
        cout << "3 * 4 = " << mul1.getResult() << endl;
        cout << "2.5 * 4.5 = " << mul2.getResult() << endl;
        cout << "1.5 * 2.5 * 3.5 = " << mul3.getResult() << endl;
        cout << "3 * 2.7 = " << mul4.getResult() << endl;
        cout << endl;
        
        Division div1(10, 2);
        Division div2(7.5, 2.5);
        Division div3(5, 2);
        
        cout << "Division:" << endl;
        cout << "10 / 2 = " << div1.getResult() << endl;
        cout << "7.5 / 2.5 = " << div2.getResult() << endl;
        cout << "5 / 2 = " << div3.getResult() << endl;
        cout << endl;
        
        // Throw exception when divisor is zero
        //Division errorDiv(5, 0); 
        
    } catch (const invalid_argument& e) {
        cerr << "Err: " << e.what() << endl;
        return 1;
    }
    
    // arithmetic demo
    cout << "==== User interactive arithmetic ====" << endl;
    char operation;
    double a, b;
    
    cout << "Enter the operands (+, -, *, /): ";
    cin >> operation;
    
    cout << "Enter two numbers: ";
    cin >> a >> b;
    
    try {
        switch (operation) {
            case '+': {
                Addition result(a, b);
                cout << a << " + " << b << " = " << result.getResult() << endl;
                break;
            }
            case '-': {
                Subtraction result(a, b);
                cout << a << " - " << b << " = " << result.getResult() << endl;
                break;
            }
            case '*': {
                Multiplication result(a, b);
                cout << a << " * " << b << " = " << result.getResult() << endl;
                break;
            }
            case '/': {
                Division result(a, b);
                cout << a << " / " << b << " = " << result.getResult() << endl;
                break;
            }
            default:
                cout << "Unsupported operand." << endl;
        }
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}