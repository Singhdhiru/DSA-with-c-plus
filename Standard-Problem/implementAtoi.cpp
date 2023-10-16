#include <iostream>
#include <climits>
#include <cctype>
// 8. String to Integer (atoi) ->leetcode

using namespace std;

int createAtoi(string s) {
    if (s.length() == 0) return 0;

    int i = 0;
    while (i < s.size() && s[i] == ' ') {
        i++;
    }
    s = s.substr(i);

    int sign = 1;
    long ans = 0;

    if (s[0] == '-') {
        sign = -1;
    }

    int MAX = INT_MAX, MIN = INT_MIN;
    i = (s[0] == '+' || s[0] == '-') ? 1 : 0;

    while (i < s.length()) {
        if (!isdigit(s[i])) break;

        ans = ans * 10 + (s[i] - '0');

        if (sign == -1 && -ans < MIN) return MIN;
        if (sign == 1 && ans > MAX) return MAX;

        i++;
    }

    return (int)(sign * ans);
}

int main() {
    string s = "  -12345";
    int result = createAtoi(s);
    cout << "Result: " << result << endl;
    return 0;
}
