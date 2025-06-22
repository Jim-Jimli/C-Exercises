/*
5. Write a program to create an integer array and allow the user to find a value from the list.
Please follow the output format.
Enter a[0] value : 23
Enter a[1] value : 3
Enter a[2] value : 43
Enter a[3] value : 25
Enter a[4] value : 21
Enter a[5] value : 8
Given list : 23,3,43,25,21 and 8.
Enter your search value: 25
Search Result : your value is located in 4th place .
Or
Enter your search value: 5
Search Result: Not found.
*/


#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <sstream>

using namespace std;

bool isNumber(const string& str) {
    return !str.empty() &&
           find_if(str.begin(), str.end(), [](unsigned char c) {
             return !isdigit(c);
           }) == str.end();
}

template<typename T>
string vectorToString(const vector<T>& vec, const string& delimiter = ", ") {
    ostringstream oss;
    
    if (!vec.empty()) {
        oss << vec[0];  // The first element
        for (size_t i = 1; i < vec.size(); ++i) {
            oss << delimiter << vec[i];  // Subsequent elements
        }
    }
    
    return oss.str();
}

int main() {

    int listSize=6,ln, sNum;
    vector<int> numbers;
    string s, sOutput;

    while (true) {
        sOutput = "";
        for (int i = 0; i < listSize; i++)
        {
            while (true)
            {
                cout << "Enter a[" << i << "] value : " << endl;
                cin >> ln;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error. Please input an integer." << std::endl;
                } else {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    numbers.push_back(ln);
                    if (sOutput!="") sOutput += ",";
                    sOutput += to_string(ln);
                    break;
                }
            }
        }

        if (!numbers.empty()) {
            int iFound = 0;
            cout << "\n Given list: " << sOutput << endl;

            cout << "Enter your search value:: " << endl;
            cin >> sNum;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error. Please input an integer." << endl;
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                size_t listSize = numbers.size();
                for (int i = 1; i < listSize; i++) {
                    if (numbers[i] == sNum) {
                        cout << "You value is located in " << i+1 << "th place" << endl;
                        iFound = 1;
                        break;
                    }
                }
                if (iFound == 0) cout << "Not found." << endl;
                break;
            }

             
        }
    }
    return 0;
}
  