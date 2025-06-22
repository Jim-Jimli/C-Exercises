/*
15. write a program to read 5 different double values and store in an array called double
list. Sort the array elements and display the sorted list.
Output Format:
Given list: 2.3, 1.2, 4.5, 6.2, 1.1
Sorted list: 1.1, 1.2, 2.3, 4.5, 6.2
*/

#include <iostream>
#include <string>
#include <cctype>
#include <random>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

template<typename T>
string vectorToString(const vector<T>& vec, const string& delimiter = ", ") {
    ostringstream oss;
    
    if (!vec.empty()) {
        oss << vec[0];  // 输出第一个元素
        for (size_t i = 1; i < vec.size(); ++i) {
            oss << delimiter << vec[i];  // 输出分隔符和后续元素
        }
    }
    
    return oss.str();
}

int main() {
    const int SIZE = 5;
    string s, outputSorted ;
    vector<double> doubles;

    while (true) {
        outputSorted = "Sorted List: " ;
        s = "";
        doubles.clear();

        cout << "Return a sorted double list. " << endl;
        cout << "Please enter 5 decimals, for example: 2.3, 1.2, 4.5, 6.2, 1.1 " << endl;
        getline(cin, s);

        // Process the number seriers with string stream 
        istringstream iss(s);
        string token;

        while (getline(iss, token, ',') && doubles.size() < SIZE) {
            // Remove the heading and ending spaces.
            token.erase(0, token.find_first_not_of(" \t"));
            token.erase(token.find_last_not_of(" \t") + 1);
            
            try {
                double num = stod(token);
                doubles.push_back(num);
            } catch (const std::invalid_argument& e) {
                std::cerr << "Warning: invalid input '" << token << "'，will be ignored." << std::endl;
            } catch (const std::out_of_range& e) {
                std::cerr << "Warning: digit '" << token << "' extends the range，will be ignored." << std::endl;
            }
        }
    
        // Check the inputted numbers.
        if (doubles.size() < SIZE) {
            cerr << "Error： " << SIZE << " numbers required, but only " << doubles.size() << " were inputted." << endl;
            continue;
        }
    
        // Sort the vector.
        sort(doubles.begin(), doubles.end());
        cout << "Given list: " << s << endl;
        cout << "Sorted list: " << vectorToString(doubles) << endl;

    }
    return 0;
}