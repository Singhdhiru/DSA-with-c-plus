#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<char, string> phone_map = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};

void backtrack(vector<string>& res, string& combination, const string& digits, int index) {
    if (index == digits.length()) {
        res.push_back(combination);
        return;
    }
    
    char digit = digits[index];
    string letters = phone_map[digit];
    
    for (char letter : letters) {
        combination.push_back(letter);
        backtrack(res, combination, digits, index+1);
        combination.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> res;
    if (digits.empty()) {
        return res;
    }
    
    string combination;
    backtrack(res, combination, digits, 0);
    
    return res;
}

int main() {
    string digits = "23";
    vector<string> res = letterCombinations(digits);
    for (string s : res) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}
