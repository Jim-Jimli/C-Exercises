/*
Write a program to display the pattern below as per the user input.
Output Format:
Enter a value: 5
1 - 1/2 + 2/4 - 4/8 + 8/16
*/

#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

bool isNumber(const string& str) {
    return !str.empty() &&
           find_if(str.begin(), str.end(), [](unsigned char c) {
             return !std::isdigit(c);
           }) == str.end();
}

int main() {

    int ns;
    string s, sOutput;

    while (true) {

        cout << "Enter a number greater than 1 : " << endl;
        cin >> s;

        if (s == "exit") break;
        
        if (!isNumber(s))
        {
            cout << "Please input not null integer! " << endl;
            continue;
        }

        ns = stoi(s); // convert the input string to integer safely.

        if (ns < 2) continue;

        sOutput = "1 ";
        for (int i = 1; i <ns; i++)
        {
            if (pow(-1,i)>0)
                sOutput += "+ ";
            else
                sOutput += "- ";
           
            sOutput += to_string((int)pow(2, i) / 2) + "/" + to_string((int)pow(2, i)) + " ";
        }
        cout << sOutput << endl;
    }
    return 0;
}
  