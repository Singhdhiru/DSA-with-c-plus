#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ? Approach -> 01(Brute Force);
// T.C : O(n^m), where n = number of words, m = length of pref
// S.C : O(n^m)
class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int totalCount = 0;
        int n = pref.size();
        for (int i = 0; i < words.size(); i++)
        {
            string str = words[i];
            int szWord = str.size();
            //? prefix size should be less then or equal to size of th word.
            if (n > szWord)
            {
                continue;
            }
            if (str.substr(0, n) == pref)
            {
                totalCount++;
            }
        }
        return totalCount;
    }
};

//*Approach-2 (Using Trie)
// T.C : O(n^l + m), where n = number of words, m = length of pref, l = average length of word
// S.C : O(n^l)
struct trieNode
{
public:
    trieNode *children[26];
    bool endOfWord;
    int count; // count perfix ending at this node
};

trieNode *getNode()
{
    trieNode *newNode = new trieNode();
    newNode->endOfWord = false;
    newNode->count = 0;
    for (int i = 0; i < 26; i++)
    {
        newNode->children[i] = NULL;
    }
    return newNode;
}
class Trie
{
public:
    trieNode *root;
    Trie()
    {
        root = getNode();
    }
    void insertWord(string &word) // o(1 )
    {
        trieNode *crawler = root;
        for (auto &ch : word)
        {
            int idx = ch - 'a';
            if (crawler->children[idx] == NULL)
            {
                crawler->children[idx] = getNode();
            }
            // move pointer
            crawler = crawler->children[idx];
            crawler->count++; // count increased for  perfix ending  at this character node
        }
        crawler->endOfWord = true;
    }
    int searchPrefixCount(string &prefix)
    {
        trieNode *crawler = root;
        for (auto &ch : prefix)
        {
            int idx = ch - 'a';
            if (crawler->children[idx] == NULL)
            {
                return 0;
            }
            crawler = crawler->children[idx];
        }
        // Means perfix ke last charecter tak present hi
        return crawler->count;
    }
};
int main()
{
    Solution solution;
    vector<string> words = {"apple", "app", "apricot", "banana", "ap"};
    string prefix = "ap";

    int count = solution.prefixCount(words, prefix);
    cout << "Number of words with prefix '" << prefix << "': " << count << endl;

    // ** Approach-2 (using trie)
    Trie trie;
    for (auto &word : words)
    {
        trie.insertWord(word);
    }
    int countP = trie.searchPrefixCount(prefix);
    cout << "number of words with perfix '" << prefix << "': " << countP << endl;

    return 0;
}
