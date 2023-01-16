// find the all element in the array->
#include <iostream>
#include <vector>
using namespace std;
vector<int> FindDuplicate(vector<int> &v)
{
    vector<int> ans;
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v.at(i) == v.at(i + 1))
        {
            ans.push_back(v.at(i));
            i = i + 1; // increment i by 1 instead of 2
        }
    }
    return ans; // return the vector of duplicates
}
int main()
{
    vector<int> v;
    v.push_back(6);
    v.push_back(6);
    v.push_back(7);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    cout << "print the vector->";
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "find all duplicate element in vector->";
    vector<int> duplicates = FindDuplicate(v); // store the returned vector in a variable
    for (int i : duplicates)
    { // iterate through the returned vector and print the values
        cout << i << " ";
    }
    cout << endl;
    return 0;
}