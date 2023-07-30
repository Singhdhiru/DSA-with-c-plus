#include <bits/stdc++.h>
using namespace std;

bool areAnagram(string a, string b)
{

    if (a.length() != b.length())
    {
        return false;
    }

    unordered_map<char, int> Map;

    for (int i = 0; i < a.length(); i++)
    {
        Map[a[i]]++;
    }

    for (int i = 0; i < b.length(); i++)
    {
        if (Map.find(b[i]) != Map.end())
        {
            Map[b[i]]--;
        }
        else
        {
            return false;
        }
    }
    for (auto items : Map)
    {
        if (items.second != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string a, b;

    cout << "String-1 = ";
    cin >> a;

    cout << "String-2 = ";
    cin >> b;

    if (areAnagram(a, b))
        cout << "\nThe two strings are anagram of each other";
    else
        cout << "\nThe two strings are NOT anagram of each other";

    return 0;
}