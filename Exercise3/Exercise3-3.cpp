/*
3. Write a program to generate multiplication times table as per the user input.
Enter a number : 3
Multiplication table: 3
*******************
1 x 3 = 3
2 x 3 = 6
10 x 3 = 30
*/

#include <string>
#include <iostream>
#include <sstream>

using namespace std;


int main() {

    string str,strOutput;


    while (true) {
        str = "";
        strOutput = "";
        cout << "Enter an integer > 0 to print a multiplication times table:";
        getline(cin, str);
        if (str=="exit") break;


        int numInput = 10;
        long xIndex = 0, yIndex = 0;

        istringstream iss(str);

        if (iss >> numInput && numInput >0 && iss.eof()) {

            cout << "Multiplication Talbe: " << numInput << endl;
            cout << "****************************" << endl;

            for (int y = 1; y <= 10; y++)
            {
                strOutput =  to_string(y) + " x " + to_string(numInput) + " = " + to_string(numInput*y);
                cout << strOutput << endl;
            }
        }
    }
    return 0;
}
