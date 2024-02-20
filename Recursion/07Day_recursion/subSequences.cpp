#include<bits/stdc++.h>
using namespace std;
/*
CodeStudio  : https://www.codingninjas.com/studio/problems/subsequences-of-string_985087?leftPanelTabValue=PROBLEM

YT -> https://www.youtube.com/watch?v=b7AYbpM5YrE
*/

// Approch 1 
// T.C -> 0(2^N)
// S.C -> O(n) -> Lenght of Input String 
void solve(vector<string>& ans, string str, string output, int i) {
    //*base case
    if(i>=str.length()) { // *ye krna pada kyuki empty string nahi send karna hi
        if(output.length()>0)
        ans.push_back(output);
        return ;
        }
    
    //*exclude
    solve(ans, str, output, i+1);
    //*include
    output.push_back(str[i]);
    solve(ans, str, output, i+1);
}
vector<string> subsequences(string str){
	vector<string> ans;
    string output = "";
    solve(ans,str,output,0); 
    return ans;
}

// ? Approach -> 2 - > Using bit manipulation
// ? T.C -> O(2^n * n) -> Reason: O(2^n) for the outer for loop and O(n) for the inner for loop.
// S.C -> O(1)
// ? Arcticals : https://takeuforward.org/data-structure/power-set-print-all-the-possible-subsequences-of-the-string/
vector<string> AllPossibleStrings(string s) {
	int n = s.length();
	vector<string>ans;
	for (int num = 0; num < (1 << n); num++) { //? 1<<n -> 2^n
		string sub = "";
		for (int i = 0; i < n; i++) {
			//check if the ith bit is set or not
			if (num & (1 << i)) {
				sub += s[i];
			}
		}
		if (sub.length() > 0) {
			ans.push_back(sub);
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}

int main() {
    string str = "abc";
    // vector<string>sub = subsequences(str);
    // ? call bitManipulation Function
    vector<string>sub = AllPossibleStrings(str);
    sort(sub.begin(), sub.end());
    for(int i=0; i<sub.size();i++){
        cout<<sub[i]<<" ";
    }
    return 0;
}