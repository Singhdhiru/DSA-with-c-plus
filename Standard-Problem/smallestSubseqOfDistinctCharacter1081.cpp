// ? same as leet code ->> 316
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// ?1081. Smallest Subsequence of Distinct Characters

string smallestSubsequence(string s) {
    vector<int> lastIdx(26, 0);
    for (int i = 0; i < s.size(); i++) {
        lastIdx[s[i] - 'a'] = i;
    }

    vector<bool> seen(26, false);
    stack<char> st; // Change the type to char
    for (int i = 0; i < s.size(); i++) {
        int curr = s[i] - 'a';
        if (seen[curr]) {
            continue;
        }
        while (!st.empty() && st.top() > s[i] && i < lastIdx[st.top() - 'a'] + 1) {
            seen[st.top() - 'a'] = false;
            st.pop();
        }
        st.push(s[i]); // Push characters, not integers
        seen[curr] = true;
    }

    string ans = "";
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string s = "bcabc";
    cout << smallestSubsequence(s) << endl;
    return 0;
}
