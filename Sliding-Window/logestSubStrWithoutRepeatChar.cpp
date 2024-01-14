#include <bits/stdc++.h>

using namespace std;
// leetcode-> 3. Longest Substring Without Repeating Characters
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

int lengthOfLongestSubstring(string s)
{
    // sliding window concept
    int lenght = 0;
    int first = 0;
    int second = 0;
    int n = s.size();
    // create vector to store count
    vector<bool> count(256, 0); // total number of char is 256
    while (second < n)
    {
        // jab count[second] pahle vist ho yani 1 present hi
        while (count[s[second]])
        {
            // window ka small kro first ko inc kro and zero set kro
            count[s[first]] = 0;
            first++;
        }
        count[s[second]] = 1;
        lenght = max(lenght, second - first );
        second++;
    }
    return lenght;
}

int main()
{
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int result = lengthOfLongestSubstring(input);
    cout << "Length of the longest substring without repeating characters: " << result << endl;

    return 0;
}
