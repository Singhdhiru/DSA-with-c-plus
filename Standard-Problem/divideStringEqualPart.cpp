#include <bits/stdc++.h> 
using namespace std;

vector<string> divideString(string &word, int n) {
    int len = word.length();

    // Check if it is possible to divide the word into N equal parts
    if (len % n != 0) {
        return {};  // Return empty vector if not possible
    }

    vector<string> result;
    int partLength = len / n; //? partlengh = 8/2 yani 4 size ka two string chahiye

    for (int i = 0; i < len; i += partLength) { //? 1 se 4 tak jayega phir i+4 se 8 tak jayega
        string part = word.substr(i, partLength);
        result.push_back(part);
    }

    return result;
}
int main() {
    string word = "abcdefgh";
    int n = 2;
    
    vector<string> divided = divideString(word, n);

    for (const auto& part : divided) {
        cout << part << " ";
    }

    return 0;
}
