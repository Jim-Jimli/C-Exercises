/*
1. Write a program to read a set of integer values and display the values in descending
order and find the middle value in the list.
Output format:
Enter your list size : 7
Enter list[0] value : 23
Enter list[1] value : 21
…..
Enter list [6] value: 3
Given list : 23,21,56,34,54,67,3
Sorted list: 67,56,54,34,23,21,3
Middle value: 34
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

    int listSize,ln;
    vector<int> numbers;
    string s, sOutput;

    while (true) {

        cout << "Enter your list size (a integer greater than 1): " << endl;
        cin >> s;
        listSize = 0;
        numbers.clear();

        if (s == "exit") break;
        
        if (!isNumber(s))
        {
            cout << "Please input not null integer! " << endl;
            continue;
        }

        listSize = stoi(s); // convert the input string to integer safely.

        if (listSize < 1) continue;

        sOutput = "";
        for (int i = 1; i <= listSize; i++)
        {
            while (true)
            {
                cout << "Enter list[" << i << "] value : " << endl;
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
            // Sort the list in decend:
            sort(numbers.begin(), numbers.end(), greater<int>());
            size_t listSize = numbers.size();

            //注：在 C++ 中，两个整数相除会执行截断除法（直接丢弃小数部分），因此使用(listSize+1)/2
            //cout << "\n the middle pos of list: " << listSize << " is " << (listSize+1)/2 << endl;
            size_t middlePos = (listSize+1)/2; 
            
            cout << "\n Given list: " << sOutput<< endl;
            cout << "The sorted list: " << vectorToString(numbers) << endl;
            cout << "The middle value: " << numbers[middlePos-1] << endl;
        }
    }
    return 0;
}
  