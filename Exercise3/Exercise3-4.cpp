/*
4. 4. Write a program to print the following,
a) *
   * *
   * * *
   * * * *
b) 
1
1 2
1 2 3
1 2 3 4

c) 
1
2 2
3 3 3
4 4 4 4

d) 
*
* *
* * *
* * * *
* * *
* *
*

e) 
*
* *
* * *
* * * *

f) 
*
~ ~
* * *
~ ~ ~ ~
* * * * *
*/

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {

    string strA1, strB1,strC1,strD1Mirror,strE1,strF1;
    string strA2,strB2,strC2,strD2,strD2Mirror,strE2,strF2;
    int layers = 4;
    strF1 = "*   ";
    strF2 =  strF1 +"\n";

    for (int y = 1; y <= layers; y++)
    {
        strA1 += "*   ";
        strA2 += strA1 + "\n";

        strB1 += to_string(y) + "   ";
        strB2 += strB1 + "\n";

        strC1 = "";
        for (int i = 1; i <= y; i++)
        {
            strC1 += to_string(y) + "   ";
        }
        strC2 += strC1 + "\n";

        if (y<4) strD2 = strA1 + "\n" + strD2;

        strE1 += "*   "; // the length of token is 4
        strE2 += string(layers * 4 / 2 - 2 * y, ' ') + strE1 + "\n";

        if (y%2==0) {
            strF1 += "*   ";
            replace(strF1.begin(), strF1.end(), '~', '*');

        } else { 
            strF1 += "~   ";
            replace(strF1.begin(), strF1.end(), '*', '~');;
        }
        strF2 += strF1 +"\n";

    }
    
    cout << strA2 << endl;
    cout << "\n\n" << strB2 << endl;
    cout << "\n\n" << strC2 << endl;
    cout << "\n\n" << strA2 << strD2 << endl;
    cout << "\n\n" << strE2 << endl;
    cout << "\n\n" << strF2 << endl;
    return 0;
}
