#include <bits/stdc++.h>
using namespace std;

// ?1239. Maximum Length of a Concatenated String with Unique Characters
// recursion code->> in Q->> constrian-> 1 <= arr.length <= 16 1 <= arr[i].length <= 26
// if constrain are thrn use memoization technique to submit
// T.C : O(n*2^n)
//S.C : O(n)
//Approach-1 Using DP (Recur + Memo)
bool hasDuplicate(string &s1, string &s2)
{
    vector<int> freq(26, 0);
    for (int i = 0; i < s1.size(); i++)
    {
        // ye check kr lega ki kahi s1 hi toh duplicate nahi hi->>arr[]={'aa', 'bb'};
        if (freq[s1[i] - 'a'] > 0)
        {
            return true;
        }
        freq[s1[i] - 'a']++;
    }
    for (int i = 0; i < s2.size(); i++)
    {
        if (freq[s2[i] - 'a'] > 0)
        {
            return true;
        }
    }
    return false;
}
int solve(int i, int n, string temp, vector<string> &arr)
{
    // base case
    if (i >= n)
    {
        return temp.size();
    }

    int include = 0;
    int exclude = 0;
    //
    if (hasDuplicate(arr[i], temp))
    {
        exclude = solve(i + 1, n, temp, arr);
    }
    else
    {
        include = solve(i + 1, n, temp + arr[i], arr);
        exclude = solve(i + 1, n, temp, arr);
    }
    return max(include, exclude);
}
int maxLength(vector<string> &arr)
{
    int i = 0;
    int n = arr.size();
    string temp = "";
    return solve(i, n, temp, arr);
}
int main()
{
    vector<string>arr = {"un","iq","ue"};
    int ans = maxLength(arr);
    cout<<"Maximum Length of a Concatenated String with Unique Characters->>"<<ans;
    return 0;
}



// memoized code->> isme clearly dikh raha two component are change idx(i) and temp
unordered_map<string, int> mp; // global declaration
int solve(int i, int n, string temp, vector<string> &arr, vector<int>&dp)
{
    // base case
    if (i >= n)
    {
        return temp.size();
    }

    if(mp.find(temp) != mp.end()){
        return mp[temp];
    }
    int include = 0;
    int exclude = 0;
    //
    if (hasDuplicate(arr[i], temp))
    {
        exclude = solve(i + 1, n, temp, arr);
    }
    else
    {
        include = solve(i + 1, n, temp + arr[i], arr);
        exclude = solve(i + 1, n, temp, arr);
    }
    return mp[temp] = max(include, exclude);
}