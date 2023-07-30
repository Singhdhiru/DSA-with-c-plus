#include <bits/stdc++.h>
using namespace std;

bool checkNoOneTomanymapping(string s1, string s2){
    unordered_map<char, char>m;
    for(int i=0; i<s1.size(); i++){
        if(m.find(s1[i]) != m.end()){
            if(m[s1[i]] != s2[i]){
                return false;
            }
        }
        else{
            m[s1[i]] = s2[i];
        }
    }
    return true;
}
bool areIsomorphic(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;
    
    // check one to one mapping from s1->s2
    bool s1s2 = checkNoOneTomanymapping(str1, str2);
    // check one to one mapping from s2->s1
    bool s2s1 = checkNoOneTomanymapping(str2, str2);

    return s1s2 && s2s1;
}

int main()
{
    string str1, str2;

    cout << "String - 1 = ";
    cin >> str1;

    cout << "String - 2 = ";
    cin >> str2;

    cout << "\nThe strings are Isomorphic? " << (areIsomorphic(str1, str2) ? "Yes" : "No");

    return 0;
}