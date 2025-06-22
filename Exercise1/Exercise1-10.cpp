/*
Write a program to generate the following pattern
Output Format:
1 + 3 + 6 + 9 + ……. N
1+ 1/2+2/3+3/4 ………. N/N+1
1+ 1/2 – 1/3 + 1/4 -1/5 ……. N
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
    string s, sOutput1, sOutput2, sOutput3;

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

        sOutput1 = "1 ";
        sOutput2 = "1 ";
        sOutput3 = "1 ";

        for (int i = 2; i <=ns; i++)
        {
            if ((i-1)*3 <= ns)
            {
                sOutput1 += " + " + to_string(((i - 1) * 3));
            }

            sOutput2 += " + " + to_string(i - 1) + "/" + to_string(i);
            sOutput3 += " + " + to_string((int)pow(-1,i)) + "/" + to_string(i);

        }
        cout << sOutput1 << endl;
        cout << sOutput2 << " + " << ns << "/" << ns+1 << endl;
        cout << sOutput3 << endl;
    }
    return 0;
}