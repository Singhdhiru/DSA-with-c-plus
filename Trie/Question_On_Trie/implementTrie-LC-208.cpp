#include <iostream>
#include <string>

using namespace std;

/*
*the time complexity for insertion, search, and prefix search is O(L), and the space complexity is O(N), 
*where L is the length of words or prefixes and N is the total number of characters in all words.
*/
class Trie {
public:
    
    struct trieNode { 
        trieNode *children[26]; 
        bool isEndOfWord; 
    };
    
    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->isEndOfWord = false;
        
        for (int i = 0; i < 26; i++) {
			newNode->children[i] = NULL;
		}
        
        return newNode;
    }
    
    /** Initialize your data structure here. */
    trieNode* root;
    
    Trie() {
        root = getNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        trieNode *crawler = root; 
        
        for (int i = 0; i < word.length(); i++) { 
            int index = word[i] - 'a'; 
            if (!crawler->children[index]) 
                crawler->children[index] = getNode();
            
            crawler = crawler->children[index]; 
        }
        
        crawler->isEndOfWord = true; 
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        trieNode *crawler = root; 
        
        for (int i = 0; i < word.length(); i++) { 
            int index = word[i] - 'a'; 
            if (!crawler->children[index]) 
                return false; 
            crawler = crawler->children[index]; 
        }
        // crawler pointer last mai word ke last char ko point kar raha hoga
        return (crawler != NULL && crawler->isEndOfWord); 
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        trieNode *crawler = root;
        int i = 0;
        for (i = 0; i < prefix.length(); i++) { 
            int index = prefix[i] - 'a'; 
            
            if (!crawler->children[index]) 
                return false; 
            
            crawler = crawler->children[index]; 
        }
        if(i==prefix.length())
            return true;
        return false;
    }
};

// Main function to demonstrate Trie functionality
int main() {
    Trie trie;

    // Insert words into the Trie
    trie.insert("hello");
    trie.insert("world");
    trie.insert("hi");
    
    // Search for words
    cout << "Search for 'hello': " << (trie.search("hello") ? "Found" : "Not Found") << endl;
    cout << "Search for 'world': " << (trie.search("world") ? "Found" : "Not Found") << endl;
    cout << "Search for 'hi': " << (trie.search("hi") ? "Found" : "Not Found") << endl;
    
    // Search for a non-existent word
    cout << "Search for 'helloworld': " << (trie.search("helloworld") ? "Found" : "Not Found") << endl;

    // Check prefixes
    cout << "Starts with 'he': " << (trie.startsWith("he") ? "Yes" : "No") << endl;
    cout << "Starts with 'wo': " << (trie.startsWith("wo") ? "Yes" : "No") << endl;
    
    return 0;
}
