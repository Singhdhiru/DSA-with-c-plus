#include<bits/stdc++.h>
using namespace std;

// ?->> 1859. Sorting the Sentence
string sortSentence(string s)
{
    // store the postion in vector of the strong word;
    vector<string> ans(10);
    string temp;
    int count = 0;
    int idx = 0;
    while (idx < s.size())
    {
        if (s[idx] == ' ')
        {
            // postion ko int mai change karna padega -'0' kar kr
            int pos = temp[temp.size() - 1] - '0';
            // last ke number ko delete kr diya
            temp.pop_back();
            // ans mai add kr diya
            ans[pos] = temp;
            // ise malum rahega kitan word vector mai add huaa
            count++;
            temp.clear();
        }
        else
        {
            temp += s[idx];
        }
        idx++;
    }
    // last word jaha per ' ' nahi hi wo ans mai add nahi ho payega use alaga se add kr lunga
    int pos = temp[temp.size() - 1] - '0';
    temp.pop_back();
    ans[pos] = temp;
    count++;
    temp.clear();

    // ab hame ans vector se nikalna hoga
    for (int i = 1; i <= count; i++)
    {
        temp += ans[i];
        temp += ' ';
    }
    // last wala word mai ' ' add ho jayega use delete karna padega
    temp.pop_back();
    return temp;
}
int main()
{
    string s = "is2 sentence4 This1 a3";
    string ans = sortSentence(s);
    cout<<"sorted sentence -> "<<ans<<endl;
    return 0;
}