#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
/*
    *MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=sTzh1L7BkQA
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings
*/

//*Approach (Using simple backtracking)
//T.C : O(n*2^n)
//S.C : O(n)
class Solution {
public:
    void solve(string& s, int idx, unordered_set<string>& st, int currCount, int& maxCount) {
        if (currCount + (s.length() - idx) <= maxCount) { //* without this cond code work smoothly
            //* Pruning for slight improvement
            return;
        }
        if (idx == s.length()) {
            maxCount = max(maxCount, currCount);
        }
        for (int j = idx; j < s.length(); j++) {
            // * .substr(idx, lenght of substring );
            string sub = s.substr(idx, j - idx + 1);
            if (st.find(sub) == st.end()) {
                st.insert(sub);
                solve(s, j + 1, st, currCount + 1, maxCount);
                // * Backtarck kar jaunga
                st.erase(sub);
            }
        }
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        int maxCount = 0;
        int currCount = 0;
        solve(s, 0, st, currCount, maxCount);
        return maxCount;
    }
};

int main() {
    Solution solution;
    string input = "ababccc"; // Example input
    int result = solution.maxUniqueSplit(input);
    
    cout << "Maximum unique splits: " << result << endl;
    return 0;
}