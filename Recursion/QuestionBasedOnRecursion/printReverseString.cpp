#include <iostream>
#include <string>

using namespace std;

string revString(const string& str) {
    if (str.length() == 1) {
        return str;
    }
    
    char currChar = str[0];
    string nextString = revString(str.substr(1));
    
    return nextString + currChar;
}

int main() {
    string str = "abcd";
    string reversed = revString(str);
    cout << reversed << endl;
    
    return 0;
}
