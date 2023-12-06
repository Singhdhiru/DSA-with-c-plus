#include <iostream>
#include <set>
#include <string>

using namespace std;

void printSubseq(const string &str, int idx, const string &res, set<string> &st)
{
    if (idx == str.length()) {
        if (st.find(res) != st.end()) {
            return;
        } else {
            cout << res << " ";
            st.insert(res);
            return;
        }
    }
    

    // choose
    printSubseq(str, idx + 1, res + str[idx], st);

    // don't choose
    printSubseq(str, idx + 1, res, st);
}

int main()
{
    string str1 = "aaa";
    set<string> st;

    printSubseq(str1, 0, "", st);

    return 0;
}
