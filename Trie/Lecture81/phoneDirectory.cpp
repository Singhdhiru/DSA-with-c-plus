#include <iostream>
#include <vector>
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
        // assumption, word will be in lowercase
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
    void insertword(string word) { 
        insertUtil(root, word); 
    }
    
    void printSuggestion(TrieNode* curr, vector<string>& temp, string prefix){
        if(curr->isTerminal){
            temp.push_back(prefix);
        }
        for(char ch='a'; ch<='z'; ch++){
            TrieNode* next = curr->childern[ch- 'a'];
            if(next != NULL){
                prefix.push_back(ch);
                printSuggestion(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }
    vector<vector<string>> getSuggestion(string str ){
        TrieNode* prev =root;
        vector<vector<string>> output;
        string prefix = "";
        for(int i=0; i<str.size(); i++){
            char lastchar = str[i];
            prefix.push_back(lastchar);

            // check last char
            TrieNode* curr = prev->childern[lastchar- 'a'];
            
            // if not found
            if(curr == NULL){
                break;
            }
            
            // if found
            vector<string>temp;
            printSuggestion(curr, temp, prefix);
            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string>& contactList, string &queryStr)
{
    Trie *t = new Trie();
    // insert all string in trie
    for(int i=0; i<contactList.size(); i++){
        string str = contactList[i];
        t->insertword(str);
    }
    return t->getSuggestion(queryStr);
}

int main()
{
    vector<string> contacts = {"john", "jacob", "jackson", "jane", "joe", "jessica"};
    string query = "ja";
    vector<vector<string>> suggestions = phoneDirectory(contacts, query);

    cout << "Suggestions for '" << query << "':" << endl;
    for (const auto& suggestion : suggestions) {
        for (const auto& word : suggestion) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
