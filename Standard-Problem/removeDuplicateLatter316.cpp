#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
// ?316. Remove Duplicate Letters

string removeDuplicateLetters(string s) {
    // ?store the last idx 
    vector<int> lastIdx(26, 0);
    for (int i = 0; i < s.size(); i++) {
        //? bcabc
        // ? 26 size ka bna lo array lastIdx[b-a]->> 1->0  aiesa hoga first iteration mai
        // ?2nd i=2->> lastidx[c-a] ->> 2->1
        // ? 3rd->> lastIdx[a-a]-> 0->2
        // ? 4th->> lastIdx[b-a]->> 1->3 yani overwrite ho jayega
        lastIdx[s[i] - 'a'] = i;
    }
    //? store the appearance of the element
    vector<bool> seen(26, false);
    stack<int> st;
    for (int i = 0; i < s.size(); i++) {
        int curr = s[i] - 'a';
        if (seen[curr]) {
            continue;
        }
        // ? ye tabhi execute hoga->top>s[i] && i se bada hi top last idx yani top abhi last mai aayega tab use push kr lenge
        while (st.size() > 0 && st.top() > s[i] && i < lastIdx[st.top() - 'a']) {
            // ? seen mai flase kr dunga jab last mai aaye toh true n ho nahi line number 19 se wapas ho jayega
            seen[st.top() - 'a'] = false;
            st.pop();
        }
        // ? push kr lo simply
        st.push(s[i]);
        // ? seen mai true kr dunga taki same element dobara push na hoo jaye
        seen[curr] = true;
    }
    string ans = "";
    while (st.size() > 0) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string input = "bcabc";
    string result = removeDuplicateLetters(input);

    cout << "Original string: " << input << endl;
    cout << "String after removing duplicate letters: " << result << endl;

    return 0;
}
