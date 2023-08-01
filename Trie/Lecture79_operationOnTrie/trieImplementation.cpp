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
    bool searchword(string word)
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

    // Delete a word from the trie
    bool deleteUtil(TrieNode *root, string word, int level)
    {
        // Base case
        if (level == word.size())
        {
            if (root->isTerminal)
            {
                root->isTerminal = false;

                // Check if the node has no other children
                for (int i = 0; i < 26; i++)
                {
                    if (root->childern[i] != NULL)
                    {
                        return false;
                    }
                }

                // If no children, then delete this node
                delete root;
                return true;
            }
            return false;
        }

        // Assumption: words will be in uppercase
        int idx = word[level] - 'A';

        // Present
        if (root->childern[idx] != NULL)
        {
            // Recursion
            bool shouldDeleteChild = deleteUtil(root->childern[idx], word, level + 1);

            if (shouldDeleteChild)
            {
                // Delete the child node and set the pointer to NULL
                delete root->childern[idx];
                root->childern[idx] = NULL;

                // Check if the current node has no other children and not a terminal node
                if (root->isTerminal)
                {
                    return false;
                }

                for (int i = 0; i < 26; i++)
                {
                    if (root->childern[i] != NULL)
                    {
                        return false;
                    }
                }

                // If no children and not a terminal node, then delete this node
                delete root;
                return true;
            }
        }
        return false;
    }

    void deleteWord(string word)
    {
        bool isPresent = searchword(word);
        if (isPresent)
        {
            if (deleteUtil(root, word, 0))
            {
                cout << "Element is deleted" << endl;
            }
            else
            {
                cout << "Failed to delete element" << endl;
            }
        }
        else
        {
            cout << "Word is not present in the trie" << endl;
        }
    }
};
int main()
{
    Trie *t = new Trie();
    t->insertword("ARP");
    t->insertword("TIME");
    t->insertword("CAT");

    cout << " word present word or not: " << t->searchword("TIM") << endl;
    cout<<"word present in trie: ";
    t->printWords();

    t->deleteWord("TIME");
    t->printWords();
    return 0;
}