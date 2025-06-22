/*
12. Write a program to read a sentence and display. Count number of words, special
characters and vowels in the sentence and display as follows,

Output Format:
Enter your sentence here: Hi, how are you?
Given sentence: “Hi, how are you? “
Special characters: 2
Words: 4
Vowels: 6
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//在 C++ 中，永远显式初始化变量是良好的编程习惯.对于结构体，推荐使用默认成员初始化或构造函数来确保成员有明确的初始值，避免未定义行为。
struct Result {
    int specialChars=0;
    int words=0;
    int vowels=0;
};


Result parseSentence(const string& str) {
    Result result;
    int numInnerSpace=0;
    char cPre='&';

    for (char c : str)
    {        
        if (!isalpha(c) && !isspace(c))
        {
            result.specialChars++;
        }

        if(!isalpha(c) && isalpha(cPre)) {
            result.words++;
        }

        if (isalpha(c) && (tolower(c) == 'a' || tolower(c)  == 'e' || tolower(c)  == 'o' || tolower(c)  == 'u' || tolower(c)  == 'i' )) {
            result.vowels++;
        }

        cPre = c;
        numInnerSpace++;
    }

    
    if( isalpha(str.back()) && isalpha(str[str.length()-2]) && numInnerSpace >0 ) {
        result.words++;
    }
    
    return result;
}

int main() {

    int ns;
    string s;
    Result r;

    while (true) {

        cout << "Enter your sentence here : " << endl;
        getline(cin,s);
        if (s == "exit") break;
        r = parseSentence(s); 

        cout << "Given sentence: " << s << endl;
        cout << "Special characters:: " << r.specialChars << endl;
        cout << "Words:: " << r.words << endl;
        cout << "Vowels:: " << r.vowels << endl;
        
    }
    return 0;
}