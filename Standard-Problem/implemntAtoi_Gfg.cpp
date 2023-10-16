#include <iostream>
#include <string>

using namespace std;

int strToInteger(string str) {
    int ans = 0;
    int sign = 1; // Assume a positive sign by default

    for (int i = 0; i < str.size(); i++) {
        int digit = str[i] - '0'; // Convert character to integer
        if (digit >= 0 && digit <= 9) {
            ans = ans * 10 + digit;
        } else if (str[i] == '-' && i == 0) { // Check if it's a negative sign at the beginning
            sign = -1;
        } else {
            return -1; // Invalid input
        }
    }

    return ans * sign;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int result = strToInteger(input);
    if (result == -1) {
        cout << "Invalid input. Please enter a valid integer string." << endl;
    } else {
        cout << "Converted integer: " << result << endl;
    }

    return 0;
}
