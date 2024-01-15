#include <bits/stdc++.h>
using namespace std;

// Question ->> 2785. Sort Vowels in a String
/*
Input: s = "lEetcOde"
Output: "lEOtcede"
Explanation: 'E', 'O', and 'e' are the vowels in s; 'l', 't', 'c', and 'd' are all consonants. The vowels are sorted according to their ASCII values, and the consonants remain in the same places.
*/
string sortVowels(string s)
{
    vector<int> lower(26, 0);
    vector<int> upper(26, 0);
    for (int i = 0; i < s.size(); i++)
    {
        // lower case
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            lower[s[i] - 'a']++;
            s[i] = '#';
        }
        // upper case
        else if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            upper[s[i] - 'A']++;
            s[i] = '#';
        }
    }
    string vowel;
    // upper case
    for (int i = 0; i < 26; i++)
    {
        char c = 'A' + i;
        while (upper[i])
        {
            vowel += c;
            upper[i]--;
        }
    }
    // lower case
    for (int i = 0; i < 26; i++)
    {
        char c = 'a' + i;
        while (lower[i])
        {
            vowel += c;
            lower[i]--;
        }
    }
    int first = 0, second = 0; //
    while (second < vowel.size())
    {
        if (s[first] == '#')
        {
            s[first] = vowel[second];
            second++;
        }
        first++;
    }
    return s;
}
int main()
{

    // Example usage:
    string input = "lEetcOde";
    string result = sortVowels(input);

    cout << "Original String: " << input << endl;
    cout << "Sorted Vowels String: " << result << endl;

    return 0;
}

// another method->>Time complexity:O(n * log(n))

// Space complexity:O(n)

// string sortVowels(string s)
// {
//     vector<char> vowels;
//     for (int i = 0; i < s.size(); i++)
//     {
//         if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
//             vowels.push_back(s[i]);
//     }
//     sort(vowels.begin(), vowels.end());
//     string ans = "";
//     int id = 0;
//     for (int i = 0; i < s.size(); i++)
//     {
        //    itna bada condition nahi likhna padta agar vowel jaha per mi, raha tha wahi # put kr dete
//         if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
//         {
//             ans += vowels[id];
//             id++;
//         }
//         else
//             ans += s[i];
//     }
//     return ans;
// }