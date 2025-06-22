/*
2. Write a program to generate multiplication times table as like,
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

            cout << "          Multiplication Talbe" << numInput << endl;
            cout << "          ********************" << endl;

            for (int y = 1; y <= numInput; y++)
            {
                cout << y << endl;
                for (int x = 1; x <= numInput; x++)
                {
                    strOutput += to_string(x*y) + "    ";
                }  
                cout << strOutput << endl;
                strOutput = "";
            }
        }
    }
    return 0;
}
