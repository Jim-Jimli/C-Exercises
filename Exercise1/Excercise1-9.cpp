/*
Write a program to read a value from user and display the place value.
Output Format:
Enter a value: 3842
“3 Thousand, 8 Hundred, 4 Ten ,2 One”
*/

#include <iostream>
#include <string>
#include <math.h>
#include <stdexcept>

using namespace std;

bool isNumber(const string& str) {
    return !str.empty() &&
           find_if(str.begin(), str.end(), [](unsigned char c) {
             return !std::isdigit(c);
           }) == str.end();
}

class NumberTranslator {
    private:
        const vector<string> positions = {
            "One", "Ten", "Hundred", "Thousand", 
            "Ten Thousand", "Hundred Thousand", 
            "Million", "Ten Million", "Hundred Million",
            "Billion", "Ten Billion", "Hundred Billion",
            "Trillion"
        };
    
    public:
        string number2Words(int num) {
            if (num <= 0) {
                throw invalid_argument("Number must be positive.");
            }
            
            vector<string> parts;
            int position = 0;
            
            while (num > 0) {
                int digit = num % 10;
                if (digit != 0) {
                        string part = to_string(digit) + " " + positions[position];
                        parts.push_back(part);
                }
                num /= 10;
                position++;
            }
            
            // 反转并连接各部分
            string result;
            for (auto it = parts.rbegin(); it != parts.rend(); ++it) {
                //迭代器类似于指针，它本身并不存储数据，而是指向容器中的某个位置。要访问该位置的数据，必须使用 * 进行解引用。
                result += *it; 
                if (next(it) != parts.rend()) {
                    result += ", ";
                }
            }
            
            return result;
        }
    };

int main() {

    int ns;
    string s, sOutput;
    NumberTranslator translator;

    while (true) {

        cout << "Enter a number greater than 0 : " << endl;
        cin >> s;

        if (s == "exit") break;
        
        if (!isNumber(s))
        {
            cout << "Please input not null integer! " << endl;
            continue;
        }

        ns = stoi(s); // convert the input string to integer safely.

        if (ns <= 0) continue;

        string words = translator.number2Words(ns);
        cout << words << endl;
    }
    return 0;
}
  