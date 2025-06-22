/*
Write a program to find a given number is prime or not. Read a number from user
and display as per the output format.
*/

#include <iostream>
#include <string>
using namespace std;

bool isNumber(const string& str) {
    return !str.empty() &&
           find_if(str.begin(), str.end(), [](unsigned char c) {
             return !std::isdigit(c);
           }) == str.end();
}

int main() {

    int n;
    string s,output;

    cout << "Prime Check: " << endl;
    cout << "******************" << endl;

    while (true) {
        cout << "Enter a number: " << endl;
        cin >> s;

        if (s == "exit") break;
        
        if (!isNumber(s))
        {
            cout << "Please input an integer! " << endl;
            continue;
        }

        n = stoi(s); // convert the input string to integer safely.
        if (n<=1) 
        {
            cout << n << " is a prime number." << endl;
            continue;
        }

        output = " is a prime number.";
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i ==0) {
                output = " is not a prime number.";
                break;
            }
        }
        cout << n << output << endl;
    }
    cout << " Program exited." << endl;
    return 0;
}
  