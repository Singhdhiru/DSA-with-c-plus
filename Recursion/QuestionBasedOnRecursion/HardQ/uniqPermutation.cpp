#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void permute(string ip, string op, vector<string> &v) {
    if (ip.size() == 0) {
        v.push_back(op);
        return;
    }
    unordered_set<char> mp;
    for (int i = 0; i < ip.size(); i++) {
        if (mp.find(ip[i]) == mp.end()) {
            mp.insert(ip[i]);
            string newip = ip.substr(0, i) + ip.substr(i + 1);
            string newop = op + ip[i];
            permute(newip, newop, v);
        }
    }
}

int main() {
    // Example usage
    string input_string = "abbc"; // all perm is 4! but unique is only 12
    vector<string> permutations;

    permute(input_string, "", permutations);

    cout << "Permutations of " << input_string << " are:" << endl;
    for (const string &perm : permutations) {
        cout << perm << " ";
    }

    return 0;
}
