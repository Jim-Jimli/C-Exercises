/*
Write a program to generate even numbers between two different values. Proceed to
verify the given inputs are not null.
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

    int ns,ne;
    string s,e,output;

    cout << "Even Number Generation: " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~ " << endl;

    while (true) {
        cout << "Enter starting number: " << endl;
        cin >> s;

        if (s == "exit") break;
        
        if (!isNumber(s))
        {
            cout << "Please input not null integer! " << endl;
            continue;
        }

        cout << "Enter final number: " << endl;
        cin >> e;

        if (e == "exit") break;
        if (!isNumber(e))
        {
            cout << "Please input not null integer! " << endl;
            continue;
        }

        ns = stoi(s); // convert the input string to integer safely.
        ne = stoi(e); // convert the input string to integer safely.
        if (ne<=ns) 
        {
            cout << " The final number should be greater than the starting number! Please enter again." << endl;
            continue;
        }

        for (int i = ns; i<= ne; i++)
        {
            if (i % 2 ==0 and i>0) {
                if (output !="") output += " ,";
                output += to_string(i);
            }
        }
        cout << "Even list between " << ns << " and " << ne << ": " << output << endl;
    }
    return 0;
}
  