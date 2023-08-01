#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;
    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie(char ch) {
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode* root, string word) {
        // base case
        if (word.size() == 0) {
            root->isTerminal = true; // last element kko terminal bna denge
            return;
        }
        // assumption, the word will be in lowercase
        int idx = word[0] - 'a';
        TrieNode* child;

        // present
        if (root->children[idx] != NULL) {
            // aage jaoo word present hi
            child = root->children[idx];
        } else {
            // absent
            // node bna do
            child = new TrieNode(word[0]);
            root->childCount++; // jab koiee char insert karenge tab child count inc
            // aage jaoo
            root->children[idx] = child;
        }
        // recursion
        insertUtil(child, word.substr(1));
    }
    void insertword(string word) {
        insertUtil(root, word);
    }

    void lcp(string str, string& ans) {
        for (int i = 0; i < str.size(); i++) {
            char ch = str[i];
            if (root->childCount == 1) {
                ans.push_back(ch);
                // aage badh jaoo
                int idx = ch - 'a';
                root = root->children[idx];
            } else {
                break;
            }
            if (root->isTerminal) {
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string>& arr, int n) {
    Trie* t = new Trie('\0');
    // insert kar do all string trie
    for (int i = 0; i < n; i++) {
        t->insertword(arr[i]);
    }
    string first = arr[0];
    string ans = "";
    t->lcp(first, ans);
    return ans;
}

int main() {
    vector<string> arr = {"apple", "app", "apricot"};
    int n = arr.size();
    string result = longestCommonPrefix(arr, n);
    cout << "Longest Common Prefix: " << result << endl;
    return 0;
}
