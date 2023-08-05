#include <iostream>
#include <string>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *childern[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            childern[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.size() == 0)
        {
            root->isTerminal = true; // last element kko terminal bna denge
            return;
        }
        // assumtion , word will be caps
        int idx = word[0] - 'a';
        TrieNode *child;

        // present
        if (root->childern[idx] != NULL)
        {
            // aage jaoo word present hi
            child = root->childern[idx];
        }
        else
        {
            // absent
            // node bna do
            child = new TrieNode(word[0]);
            // aage jaoo
            root->childern[idx] = child;
        }
        // recursion
        insertUtil(child, word.substr(1));
    }
    void insertword(string word)
    {
        insertUtil(root, word);
    }

    // search elements
    bool searchUtil(TrieNode *root, string word)
    {
        // base case
        if (word.size() == 0)
        {
            return root->isTerminal;
        }
        // assumtion , word will be caps
        int idx = word[0] - 'a';
        TrieNode *child;

        // present
        if (root->childern[idx] != NULL)
        {
            // aage jaoo word present hi
            child = root->childern[idx];
        }
        else
        {
            // absent
            return false;
        }
        // recursion
        return searchUtil(child, word.substr(1));
    }
    bool searchword(string word)
    {
        return searchUtil(root, word);
    }
};

int countDistinctSubstring(string s)
{
    Trie a;
    int count = 0; // Initialize with 0
    for (int i = 0; i < s.length(); i++)
    {
        for (int len = 1; len <= s.length() - i; len++)
        {
            string word = s.substr(i, len);
            if (!a.searchword(word))
            {
                a.insertword(word);
                count++;
            }
        }
    }
    return count + 1;
}

int main()
{
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int result = countDistinctSubstring(input);
    cout << "Number of distinct substrings: " << result << endl;

    return 0;
}
