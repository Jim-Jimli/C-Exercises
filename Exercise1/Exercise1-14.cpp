/*
14. write a program to create an integer array of size 10 and display. Count number of
even numbers and number of odds in the list and display as follows
Output Format:
Enter 10 values: 12,34,12,43,54,67,3,78,23,67.
Even List: 12,34,12,54,78
Odd List: 43,67,3,23,67
No. of Evens: 5
No. of Odds: 5
*/

#include <iostream>
#include <string>
#include <cctype>
#include <random>
#include <unordered_map>
#include <sstream>

using namespace std;

int main() {
    const int SIZE = 10;
    int numEven, numOdd;
    string s, outputEven, outputOdd ;
    vector<int> numbers;

    while (true) {
        outputEven = "Even List: " ;
        outputOdd = "Odd List: " ;
        numEven = 0;
        numOdd = 0;
        s = "";
        numbers.clear();

        cout << "Even and Odd numbers count. " << endl;
        cout << "Please enter 10 integers, for example:1,2,3,4,5,6,7,8,9,10 " << endl;
        getline(cin, s);

        // Process the number seriers with string stream 
        istringstream iss(s);
        string token;

        while (getline(iss, token, ',') && numbers.size() < SIZE) {
            // Remove the heading and ending spaces.
            token.erase(0, token.find_first_not_of(" \t"));
            token.erase(token.find_last_not_of(" \t") + 1);
            
            try {
                int num = stoi(token);
                numbers.push_back(num);
            } catch (const std::invalid_argument& e) {
                std::cerr << "Warning: invalid input '" << token << "'，will be ignored." << std::endl;
            } catch (const std::out_of_range& e) {
                std::cerr << "Warning: digit '" << token << "' extends the range，will be ignored." << std::endl;
            }
        }
    
        // Check the inputted numbers.
        if (numbers.size() < SIZE) {
            cerr << "Error： " << SIZE << " numbers required, but only " << numbers.size() << " were inputted." << endl;
            continue;
        }
    
        // Count the numbers of evens and odds.
        for (int num : numbers) {
            if (num % 2 == 0) {
                numEven++;
                if (outputEven != "Even List: ")  outputEven += ", " ;
                outputEven += to_string(num);
            }
            else {
                numOdd++;
                if (outputOdd != "Even List: ")  outputOdd += ", " ;
                outputOdd += to_string(num);
            }
        }
        cout << outputEven << endl;
        cout << outputOdd << endl;
        cout << "No. of Evens: " << numEven << endl;
        cout << "No. of Odds: " << numOdd << endl;

    }
    return 0;
}