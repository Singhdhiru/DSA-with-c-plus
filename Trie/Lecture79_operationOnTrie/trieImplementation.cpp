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
        int idx = word[0] - 'A';
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
        int idx = word[0] - 'A';
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
    bool  searchword(string word)
    {
        return searchUtil(root, word);
    }

    // print the word present in the trie
        void printWordsUtil(TrieNode *root, string currentWord)
    {
        if (root->isTerminal)
        {
            cout << currentWord << endl;
        }

        for (int i = 0; i < 26; i++)
        {
            if (root->childern[i] != NULL)
            {
                printWordsUtil(root->childern[i], currentWord + root->childern[i]->data);
            }
        }
    }

    void printWords()
    {
        printWordsUtil(root, "");
    }
};
int main()
{
    Trie *t = new Trie();
    t->insertword("ARP");
    t->insertword("TIME");
    t->insertword("CAT");

    cout<<" word present word or not: "<<t->searchword("TIM")<<endl;

    t->printWords();
    return 0;
}