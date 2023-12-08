#include <iostream>
#include <string>

using namespace std;

void printPermutation(const string& str, int idx, const string& perm) {
    if (str.length() == 0) {
        cout << perm << " ";
        return;
    }

    for (int i = 0; i < str.length(); i++) {
        char currChar = str[i];
        // if i = b then substr(0, i)-> a hoga 
        string newStr = str.substr(0, i) + str.substr(i + 1);
        printPermutation(newStr, idx + 1, perm + currChar);
    }
}

int main() {
    string str = "abc";
    printPermutation(str, 0, "");

    return 0;
}
