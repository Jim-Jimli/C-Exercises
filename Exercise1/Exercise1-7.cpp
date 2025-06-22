/*
Write a program to read a number from user, find factorial for the given number and
display as like,
Output Format:
Enter a value: 5
Factorial of 5 is 120.
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

    int ns;
    long long nOutput;
    string s;

    while (true) {

        cout << "Enter a number greater than 1 to calculate its factorial: " << endl;
        cin >> s;

        if (s == "exit") break;
        
        if (!isNumber(s))
        {
            cout << "Please input not null integer! " << endl;
            continue;
        }

        ns = stoi(s); // convert the input string to integer safely.

        if (ns < 2) continue;

        nOutput = ns;
        for (int i = ns-1; i > 1; i--)
        {
            nOutput = nOutput * i;
        }
        cout << "Factorial of " << ns << " is " << nOutput << endl;
    }
    return 0;
}
  