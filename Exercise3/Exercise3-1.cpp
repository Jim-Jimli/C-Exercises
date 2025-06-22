/*
1. Write a program to display the following. Allow the user to provide input as like,
Enter a value: 10 (if the user given 10, your application as to generate the following figure)
*
* * *
* * * * *
* * * * * * *
* * * * * * * * *
*/

#include <string>
#include <iostream>
#include <sstream>

using namespace std;


int main() {

    string str, strOutput="";
    int numInput,numIterator;

    while (true) {
        str = "";
        cout << "Please enter an integer greater than 0:";
        getline(cin, str);
        strOutput = "";
        if (str=="exit")
            break;

        istringstream iss(str);

        if (iss >> numInput && numInput >0 && iss.eof()) {
            numIterator = (numInput-1) / 2;
            strOutput = "*";
            cout << strOutput << endl;
            
            for (int i = 1; i <= numIterator; i++)
            {
                strOutput += " * *";
                cout << strOutput << endl;
            }
        }
    }
    return 0;
}
