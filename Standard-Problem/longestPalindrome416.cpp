#include <iostream>
#include <vector>
using namespace std;

// ? leet code 409. Longest Palindrome
/*
Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
? jita even use toh add kr lenge aur odd mai se -1 kr lenge and last ak element add kr lenge bich mai jise koiee fark nahi oadega 
*/
int longestPalindrome(string s)
{
    vector<int> lower(26, 0);
    vector<int> upper(26, 0);

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            lower[s[i] - 'a']++;
        }
        else
        {
            upper[s[i] - 'A']++;
        }
    }

    int count = 0;
    int odd = 0;

    for (int i = 0; i < 26; i++)
    {
        if (lower[i] % 2 == 0)
        {
            count += lower[i];
        }
        else
        {
            count += lower[i] - 1;
            odd = 1;
        }

        if (upper[i] % 2 == 0)
        {
            count += upper[i];
        }
        else
        {
            count += upper[i] - 1;
            odd = 1;
        }
    }

    return count + odd;
}

int main()
{
    // Example usage of longestPalindrome function
    string inputString = "abccccdd";
    int result = longestPalindrome(inputString);

    // Display the result
    cout << "Longest Palindrome Length: " << result << endl;

    return 0;
}
