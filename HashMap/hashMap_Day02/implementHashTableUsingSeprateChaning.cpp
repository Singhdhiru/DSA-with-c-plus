#include <bits/stdtr1c++.h>
#include <list>
#include <vector>
#include <iterator>
using namespace std;
class Hashing
{
    public:
    vector<list<int>> hashTable;
    int buckets;

    Hashing(int size)
    {
        buckets = size;
        hashTable.resize(size);
    }

    int hashValue(int key)
    {
        return key % buckets; // division method to fund hash value
    }
    void addKey(int key)
    {
        int idx = hashValue(key);
        hashTable[idx].push_back(key);
    }

    bool searchKey(int key) // Return a boolean indicating whether the key was found or not
    {
        int idx = hashValue(key);
        auto it = find(hashTable[idx].begin(), hashTable[idx].end(), key);
        return it != hashTable[idx].end();
    }

    void deleteKey(int key)
    {
        int idx = hashValue(key);
        auto it = find(hashTable[idx].begin(), hashTable[idx].end(), key);
        if (it != hashTable[idx].end())
        {
            hashTable[idx].erase(it);
            cout << key << " is deleted" << endl;
        }
        else
        {
            cout << "Key not found in hash table" << endl;
        }
    }

    // another method to delete
    // void remove(int key)
    // {
    //     int index = hashFunction(key); // Compute the hash index

        // Search for the key in the list
    //     for (auto it = table[index].begin(); it != table[index].end(); ++it)
    //     {
    //         if (it->first == key)
    //         {
    //             table[index].erase(it); // Remove the pair from the list
    //             return;
    //         }
    //     }
    // }
};


int main()
{
    Hashing hashTable(10); // Create a hash table with 10 buckets

    // Add keys to the hash table
    hashTable.addKey(5);
    hashTable.addKey(15);
    hashTable.addKey(25);

    // Search for a key in the hash table
    int searchKey = 15;
    if (hashTable.searchKey(searchKey))
    {
        cout << "Key " << searchKey << " found in the hash table" << endl;
    }
    else
    {
        cout << "Key " << searchKey << " not found in the hash table" << endl;
    }

    // Delete a key from the hash table
    int deleteKey = 5;
    hashTable.deleteKey(deleteKey);

    return 0;
}