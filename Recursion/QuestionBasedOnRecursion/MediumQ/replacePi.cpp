// Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
// Constraints :
// 1 <= |S| <= 50
// where |S| represents the length of string S. 
// Constraints :
// 1 <= |S| <= 50
// where |S| represents the length of string S. 
// Sample Input 1 :
// xpix
// Sample Output :
// x3.14x

#include <iostream>
using namespace std;
// Function to replace occurrences of "pi" with "3.14" in a character array
void replacePi(char input[]) {
    // base case
    if (input[0] == '\0' || input[1] == '\0') {
        return;
    }
    // agar char arry ppi ho toh isliye ak postion move karenge
    if (input[0] != 'p' || input[1] != 'i') {
        replacePi(input + 1);
    } else {
        int lastIdx = 0;
        while (input[lastIdx] != '\0') {
            lastIdx++;
        }
        // char array ko shift kr do
        while (lastIdx >= 2) {
            input[lastIdx + 2] = input[lastIdx];
            lastIdx--;
        }
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
        replacePi(input + 4);
    }
}

// Main function for testing the replacePi function
int main() {
    char str[] = "pipi";
    replacePi(str);
    cout << "Modified String: " << str << endl;
    return 0;
}
