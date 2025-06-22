/*
Write a program to generate Fibonacci series as per the user input.
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

    int ns,n1=0,n2=1;
    string s,output;

    while (true) {
        output = "1, 1";
        n1=0,n2=1;
        cout << "Enter a number greater than 1 to generate a Fibonacci series: " << endl;
        cin >> s;

        if (s == "exit") break;
        
        if (!isNumber(s))
        {
            cout << "Please input not null integer! " << endl;
            continue;
        }

        ns = stoi(s); // convert the input string to integer safely.

        if (ns < 2) continue;

        for (int i = 2; i<= ns; i=n1+n2)
        {
            n1 = n2;
            n2 = i;
            output += " , " + to_string(i);
        }
        cout << "The  Fibonacci series is: " << output << endl;
    }
    return 0;
}
  