#include <iostream>
#include <string>
using namespace std;

struct TrieNode
{
    TrieNode *children[26];
    bool isTerminal;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

// Function to insert a word into the Trie.
void insert(TrieNode *root, string key)
{
    TrieNode *current = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (current->children[index] == NULL)
        {
            current->children[index] = new TrieNode();
        }
        current = current->children[index];
    }
    current->isTerminal = true;
}

// Function to search for a word in the Trie.
bool search(TrieNode *root, string key)
{
    TrieNode *current = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (current->children[index] == NULL)
        {
            return false;
        }
        current = current->children[index];
    }
    return current->isTerminal;
}

// Function to search for a prefix in the Trie.
bool prefixUtil(TrieNode *root, string word)
{
    // base case
    if (word.size() == 0)
    {
        return true;
    }
    // assumption: word will be in lowercase
    int idx = word[0] - 'a';
    TrieNode *child;

    // present
    if (root->children[idx] != NULL)
    {
        // go ahead, word is present
        child = root->children[idx];
    }
    else
    {
        // absent
        return false;
    }
    // recursion
    return prefixUtil(child, word.substr(1));
}

// Returns if there is any word in the trie that starts with the given prefix.
bool startsWith(TrieNode *root, string prefix)
{
    return prefixUtil(root, prefix);
}

int main()
{
    TrieNode *root = new TrieNode();

    insert(root, "hello");
    insert(root, "world");
    insert(root, "trie");
    insert(root, "data");
    insert(root, "structure");

    cout << "Search results:\n";
    cout << "hello: " << (search(root, "hello") ? "Found" : "Not Found") << endl;
    cout << "world: " << (search(root, "world") ? "Found" : "Not Found") << endl;
    cout << "trie: " << (search(root, "trie") ? "Found" : "Not Found") << endl;
    cout << "data: " << (search(root, "data") ? "Found" : "Not Found") << endl;
    cout << "structure: " << (search(root, "structure") ? "Found" : "Not Found") << endl;
    cout << "algorithm: " << (search(root, "algorithm") ? "Found" : "Not Found") << endl;

    cout << "Prefix search results:\n";
    cout << "he: " << (startsWith(root, "he") ? "Found" : "Not Found") << endl;
    cout << "wor: " << (startsWith(root, "wor") ? "Found" : "Not Found") << endl;
    cout << "cat: " << (startsWith(root, "cat") ? "Found" : "Not Found") << endl;
    cout << "dat: " << (startsWith(root, "dat") ? "Found" : "Not Found") << endl;

    return 0;
}
