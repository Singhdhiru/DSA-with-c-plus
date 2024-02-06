#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=3Bp3OVD1EGc
    Company Tags                : Google, Amazon, Microsoft, Codenation, FactSet, , Atlassian, MakeMyTrip, Streamoid Technologies, Media.net, Airbnb
    Leetcode Link               : https://leetcode.com/problems/minimum-window-substring/
*/
string minWindow(string s, string t) {
        int n = s.size();
        if(t.size()>n){
            return "";
        }
        //? GFG per same question solve karne ke liye map ke jagahh per vector use karna padega
        unordered_map<char,int>mp;
        for(char &ch:t){
            mp[ch]++;
        }
        int requiredCount = t.size();
        int minWindowSize = INT_MAX;
        int start_i = 0;
        int i=0; 
        int j= 0;
        while(j<n){
            char ch = s[j];
            if(mp[ch]>0){
                requiredCount--;
            }
            mp[ch]--;
            // try to shrink window
            while(requiredCount == 0){
                // window size ko update kr lo
                if(minWindowSize > j-i+1){
                    minWindowSize = j-i+1;
                    // start i ko update kr diya taki last wahi substr nikal lunga
                    start_i = i;
                }
                char ch_i = s[i];
                mp[ch_i]++;
                if(mp[ch_i]>0){
                    requiredCount ++;
                }
                i++;
            }
            j++;
        }
        
        return minWindowSize == INT_MAX ? "" : s.substr(start_i, minWindowSize);
    }
int main() {
    // Example usage of minWindow function
    string s = "ADOBECODEBANC";
    string t = "ABC";

    string result = minWindow(s, t);

    // Display the result
    cout << "Minimum window substring: " << result << endl;

    return 0;
}
