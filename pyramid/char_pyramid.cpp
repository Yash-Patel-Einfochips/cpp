#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string entered_str;
    cout << "Enter the chracter string: ";
    getline(cin, entered_str);
    cout << "Entered string is: " << entered_str << endl;

    int str_length = entered_str.length();
    if (str_length % 2 == 0) {
        cout << "Unable to proceed" << endl;
        return 0;
    }

    int i,j;

    for (i=0, j=str_length; i<str_length, j>0; i++, j--) {
        cout << string(j-1, ' ');
        string sub_str = entered_str.substr(0, i+1);
        string rev_str = sub_str;
        reverse(rev_str.begin(), rev_str.end());
        rev_str.erase(0,1);
        cout << sub_str << rev_str << endl;
    }
    
    return 0;
}