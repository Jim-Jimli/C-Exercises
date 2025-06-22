/*
Write a program to generate an odd list between 20 to 47 and count number of odds in
the list. Display your result as per the output format.
Output Format:
Odd list between 20 to 47: 21, 23, …… 47
Number of Odds between 20 to 47: 14
*/

#include <iostream>
#include <string>
using namespace std;


int main() {

    int ns=20,ne=47, nOdds=0;
    string output;

    for (int i = ns; i<= ne; i++)
    {
        if (i % 2 ==1 and i>0) {
            if (output !="") output += " ,";
            output += to_string(i);
            nOdds++;
        }
    }
    cout << "Odd list between 20 to 47: " << output << endl;
    cout << "Number of Odds between 20 to 47: " << nOdds << endl;
    return 0;
}
  