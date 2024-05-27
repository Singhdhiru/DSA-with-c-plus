#include <iostream>
#include <vector>
#include <string>
#include <climits> // For INT_MIN
using namespace std;

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Vn2eno9OIpc
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/maximum-score-words-formed-by-letters
*/
// Using simple backtracking
// T.C : O(2^n) where n is the total number of words
// S.C : O(n)
class Solution
{
public:
    int maxScore;
    int n;
    void solve(int i, vector<int> &score, vector<string> &words, int currScore, vector<int> &freq)
    {
        maxScore = max(maxScore, currScore);

        // base case
        if (i >= n)
        {
            return;
        }

        vector<int> tempFreq = freq; // ye kiya kyuki agar word ko le liya tohfreq change ho jayega toh ham us time
        // updated freq bejenge
        int j = 0;
        int tempScore = 0;
        while (j < words[i].size())
        {
            char ch = words[i][j];
            tempFreq[ch - 'a']--;
            tempScore += score[ch - 'a'];
            if (tempFreq[ch - 'a'] < 0)
            {
                break;
            }
            j++;
        }
        // Take words[i]
        if (j == words[i].length())
        {                                                                // It means we could form the word words[i]
            solve(i + 1, score, words, currScore + tempScore, tempFreq); // word liya ho tohusme updated freq-> tempFreq bejo
        }

        // Not Take words[i]
        solve(i + 1, score, words, currScore, freq); // isme update freq mt bejo kyuki isme word nahi liya hu
    }
    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
    {
        vector<int> freq(26, 0);
        for (auto &ch : letters)
        {
            freq[ch - 'a']++;
        }
        maxScore = INT_MIN;
        n = words.size();
        solve(0, score, words, 0, freq);
        return maxScore;
    }
};

int main()
{
    // Example input
    vector<string> words = {"dog", "cat", "dad", "good"};
    vector<char> letters = {'a','a','c','d','d','d','g','o','o'};
    vector<int> score = {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};

    Solution solution;
    int result = solution.maxScoreWords(words, letters, score);

    cout << "Maximum Score: " << result << endl;

    return 0;
}
