/*
Write a program to read the first name and last name. Validate the user inputs as
follows
• Verify first name and last name are different
• Verify the name contains only alphabets

Output Format:
First name : manju
Last name : manju

“ Please provide different surname “
First name : manju
Last name : $parthi

“Please provide only letters “
First name : manju
Last name : Parthi
“ Hi Manju Parthi “
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isFirstNameNEQLastName(const string& sFirstName, const string& sLastName) {
    return !sFirstName.empty() &&
           !sLastName.empty() &&
           sLastName == sFirstName;
}

bool isAlphabetic(const string& str) {
    for (char c : str) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

int main() {

    int ns;
    string sFirstName, sLastName;

    while (true) {

        cout << "First name : " << endl;
        cin >> sFirstName;
        if (sFirstName == "exit") break;

        cout << "Last name : " << endl;
        cin >> sLastName;
        if (sLastName == "exit") break; 
        
        if (isFirstNameNEQLastName(sFirstName, sLastName)){
            cout << " Please provide different surname! " << endl;
            continue;
        }
        
        if (!isAlphabetic(sFirstName) or !isAlphabetic(sLastName) )
        {
            cout << "Please provide only letters! " << endl;
            continue;
        }
        cout << "Hi " << sFirstName << " " << sLastName << endl;

    }
    return 0;
}