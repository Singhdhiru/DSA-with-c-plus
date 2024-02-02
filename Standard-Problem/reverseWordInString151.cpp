#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include<algorithm>
using namespace std;
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=mdej8UiRCkI
    Company Tags                 : Amazon (With variations), Microsoft, MentorGraphics, MakeMyTrip, Accolite, Adobe, Cisco, Goldman Sachs,Paytm,Samsung, SAP Labs
    Leetcode Link                : https://leetcode.com/problems/reverse-words-in-a-string/
*/
// Approach-1 (Perfect use of std::stringstream)
string reverseWords_ssString(string s)
{
    stringstream ss(s);
    string token = "";

    string result = "";
    // By default stringstream tokenizes on ' ' (space character)
    // Know more : https://github.com/MAZHARMIK/Cpp-STL-Quick-Help/blob/main/README.md
    while (ss >> token)
    {
        result = token + " " + result;
    }

    return result.substr(0, result.length() - 1);
}
// Approach-2 (using stack data structures)
// t.c->O(n)
// S.C->O(n)
string reverseWords_Stack(string str)
{
    int n = str.size();

    stack<string> st;

    int startIndex = 0;

    for (int i = 0; i <= n; i++)
    {

        if (str[i] == ' ' || i == n)
        {

            string s = str.substr(startIndex, i - startIndex);

            if (!s.empty())
            { // Check if the substring is not empty

                st.push(s);
            }

            startIndex = i + 1;
        }
    }

    string ans = "";

    while (!st.empty())
    {

        ans += st.top();

        ans += " ";

        st.pop();
    }

    // Trim trailing space

    if (!ans.empty() && ans.back() == ' ')
    {

        ans.pop_back();
    }

    return ans;
}

// Approach-2 (Two Pointer)
string reverseWords(string s)
{
    // story
    // 1. reverse whole string

    reverse(s.begin(), s.end());

    int i = 0;
    // hero honge hamare l and r jo revrese karenge words ko
    int l = 0, r = 0;

    int n = s.length();

    while (i < n)
    {
        while (i < n && s[i] != ' ')
        { // i ko agar char dikha to r ko dega and i++ and r++
            s[r++] = s[i++];
        }

        if (l < r)
        { // l     r
            reverse(s.begin() + l, s.begin() + r);

            s[r] = ' ';
            r++;

            l = r;
        }

        i++; // y eto badhta rahega
    }

    s = s.substr(0, r - 1);

    return s;
}
int main()
{
    string s = "the sky is blue";
    cout<<reverseWords(s)<<endl;
    return 0;
}