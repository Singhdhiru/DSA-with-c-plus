
#include <bits/stdc++.h>
using namespace std;

/*
MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=qases-9gOpk
    Company Tags                : MICROSOFT
    GfG Link                    : https://www.geeksforgeeks.org/problems/search-pattern0205/1
*/
//?Approach-1 (Brute Force)
// Simply try with every possible index at i and iterate on pattern and keep trying.
// T.C : O(m*n)
// S.C : O(1)

//?Approach-2 (KMP Algorithm)
// T.C : O(m+n)
// S.C : O(m) where m is the length of pattern
void computeLSP(string &pat, vector<int> &lps, int m)
{
    int len = 0; // Length of the previous longest prefix & suffix

    lps[0] = 0; // Because there is no proper suffix and prefix of pattern[0..0]

    int i = 1;
    while (i < m)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1]; // You can also write, len = len-1;
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
vector<int> search(string txt, string pat)
{
    int n = txt.size();
    int m = pat.size();

    vector<int> res;
    // Create an LPS array to store the longest proper prefix which is also a suffix
    // lps[i] = the longest proper prefix of pat[0..i] which is also a suffix of pat[0..i].
    vector<int> LPS(m, 0);
    computeLSP(pat, LPS, m);

    int i = 0; // Index for text
    int j = 0; // Index for pattern

    while (i < n)
    {
        if (pat[j] == txt[i])
        {
            i++;
            j++;
        }
        // ? first pat mil gaya
        else if (j == m) // Pattern found at index i-j (If you have to return 0 Based indexing)
        {
            res.push_back(i - j+1);
            // ? first milne ke baad uske piche wale idx ka lsp puch lunaga
            j = LPS[j - 1];
        }
        else if (i < n && pat[j] != txt[i])
        {
            if (j != 0)
            { //? ye check daal diya ki j ko upadte sahi se kare jab j>0 nahi toh dikkatt ho jYEG
                j = LPS[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    return res;
}
int main()
{
    string txt = "geeksforgeeks";
    string pat = "geeky";
    vector<int> ans = search(txt, pat);
    if(ans.size() == 0){
        cout<<"-1"<<endl;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
