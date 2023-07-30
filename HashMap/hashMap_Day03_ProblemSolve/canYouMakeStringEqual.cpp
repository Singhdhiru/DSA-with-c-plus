#include <bits/stdc++.h>
using namespace std;

bool canMakeEqual(vector<string> a)
{

    unordered_map<char, int> m;
    for (auto s : a)
    {
        for (auto c : s)
        {
            m[c]++;
        }
    }

    int n = a.size();

    for (auto i : m)
    {
        if (i.second % n != 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    vector<string> a;
    string s;
    int n;

    cout << "Enter number of strings: ";
    cin >> n;

    cout << "Enter all the strings: ";
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        a.push_back(s);
    }

    cout << "Can you make the strings equal? " << (canMakeEqual(a) ? "Yes" : "No");

    return 0;
}
