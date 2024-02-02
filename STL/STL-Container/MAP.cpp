// What is map in C++ STL?
// ?map in STL are associative containers where each element consists of a key value and a
// mapped valueTwo mapped values cannot have the same key value.
// Syntax:
//? map<object_type,object_type> variable_name;

#include <bits/stdc++.h>
using namespace std;
int main()
{

    // ? intialize map
    map<int, int> mp;

    // *take input ia map
    for (int i = 1; i < 5; i++)
    {
        mp.insert({i, i * 5});
    }

    // ? print the element present in the map
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    // ?find function
    int n = 2;
    if (mp.find(2) != mp.end())
        cout << n << " is present in map" << endl;

    // ? erase function
    mp.erase(mp.begin());
    cout << "Elements after deleting the first element: " << endl;
    cout << "Key\tElement" << endl;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << "\t" << it->second << endl;
    }

    cout << "The size of the map is: " << mp.size() << endl;

    if (mp.empty() == false)
        cout << "The map is not empty " << endl;
    else
        cout << "The map is empty" << endl;
    mp.clear();
    cout << "Size of the map after clearing all the elements: " << mp.size();
}