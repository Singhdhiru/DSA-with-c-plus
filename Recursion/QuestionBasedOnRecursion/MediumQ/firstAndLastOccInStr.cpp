#include <iostream>
#include <string>

using namespace std;

// first and last ko global bna diya kyuki recursion call stack mai baar baaar intialize hoga
int first = -1;
int last = -1;

void getIndices(const string& str, char el, int idx) {
    if (idx == str.length()) {
        return;
    }

    if (str[idx] == el) {

        if (first == -1) {
            first = idx;
        }
        else {
            last = idx;
        }
    }

    getIndices(str, el, idx + 1);
}

int main() {
    string str = "tabcdfghijakkk";
    getIndices(str, 'a', 0);

    // Using '\n' instead of endl to avoid flushing the output buffer unnecessarily
    cout << "First occurrence : " << first << '\n';
    cout << "Last occurrence : " << last << '\n';

    return 0;
}
