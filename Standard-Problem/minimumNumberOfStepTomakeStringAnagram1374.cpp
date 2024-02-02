#include <bits/stdc++.h>
using namespace std;
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=dDQTlfWvzqE
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
*/

/****************************************************** C++ ******************************************************/
//Approach-1 (Using 2 counters)
//T.C : O(n)
//S.C : O(26) ~ O(1)
int minSteps_usingToFreqArray(string s, string t) {
        int n = s.size();
        // Dono String ks frequency store kar liya
        vector<int>freq1(26, 0);
        vector<int>freq2(26,0);
        for(int i = 0; i<n; i++){
            freq1[s[i]-'a']++;
            freq2[t[i]-'a']++;
        }
        // freq ko traverse kar liya
        int result = 0;
        for(int i=0; i<26; i++){
            int freq_t = freq1[i];
            int freq_s = freq2[i];
            // s = bab, t = aba
            // t mai do b hona chahiye yani pahle 1 hi means freq(b in s)- freq(b in t)
            if(freq_t < freq_s){
                result += freq_s-freq_t;
            }
        }
        return result;
    }
//Approach-2 (Using 1 counter)
//T.C : O(n)
//S.C : O(26) ~ O(1)
int minSteps(string s, string t) {
        int n = s.length();
        
        int mp[26] = {0};
        // ak hi freq vector mai kaam kar liya
        for(int i = 0; i<n; i++) {
            mp[s[i] - 'a']++; // add kiya
            mp[t[i] - 'a']--;  // subtract kar diya
        }

        int result = 0;

        for(int i = 0; i < 26; i++) {
            // dry kar ke dekho 
            // agar neg ho to koiee dikkat nahi hi
            // pos bach ho toh use answer mai add kar lo
            result += max(0, mp[i]);
        } 
        
        return result;
    }

int main() {
    string st1 = "bba";
    string st2 = "aaa";
    int ans = minSteps(st1, st2);
    cout<<"Total move to make string anagram->> "<<ans<<endl;
    return 0;
}