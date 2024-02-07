#include <bits/stdc++.h>
using namespace std;
/*
?MY YOUTUBE VIDEO ON THIS Qn : Using Sortng     - https://www.youtube.com/watch?v=--k5-3EOObs&t=2s
?Without Sorting  - https://www.youtube.com/watch?v=TNe3gF4r128&t=1s
Company Tags                : Amazon(mutiple times), Google, Uber, Facebook, Bloomberg, Yahoo, Goldman Sachs, Microsoft, Apple, Walmart Labs, Twilio, Affirm
Leetcode Link               : https://leetcode.com/problems/group-anagrams/
GfG Link      : https://practice.geeksforgeeks.org/problems/print-anagrams-together/1
*/
//?Approach-1 (Using Sorting)
// T.C : O(n*klog(k))  (n = size of input, k = maximum length of a string in the input vector)
// S.C : O(n*k)
vector<vector<string>> groupAnagrams_usingSorting(vector<string> &strs)
{
    unordered_map<string, vector<string>> mp;

    for (auto str : strs)
    {
        string temp = str;
        sort(temp.begin(), temp.end());
        mp[temp].push_back(str);
    }

    vector<vector<string>> result;
    for (auto it : mp)
    {
        result.push_back(it.second);
    }

    return result;
}

//?Approach-2
// T.C : O(n*k)  (n = size of input, k = maximum length of a string in the input vector)
// S.C : O(n*k)
string generate(string &s)
{
    // count array bna liya 
    int count[26] = {0};

    // count arrray mai uska freq store kar lunga
    for (char &ch : s)
    {
        count[ch - 'a']++;
    }

    string new_s;

    for (int i = 0; i < 26; i++)
    {

        if (count[i] > 0)
        {
            // uskw freq se nya word bna lunga
            new_s += string(count[i], i + 'a');
        }
    }

    return new_s;
}

vector<vector<string>> groupAnagrams_withOutSorting(vector<string> &strs)
{
    unordered_map<string, vector<string>> mp;

    for (string &s : strs)
    {
        string new_s = generate(s);

        mp[new_s].push_back(s);
    }

    vector<vector<string>> result;
    for (auto &it : mp)
    {
        result.push_back(std::move(it.second));
    }

    return result;
}
int main()
{
    vector<string> nums = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> res = groupAnagrams_withOutSorting(nums);
    // print the results
    int n = res.size();
    for (int i = 0; i < n; i++)
    {
        int m = res[i].size();
        for (int j = 0; j < m; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}