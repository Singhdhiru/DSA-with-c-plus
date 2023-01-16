#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> Find3sum(vector<int> &v, int target)
{
    vector<vector<int>> ans; // intialize ans vector to store triplate
    // sort theninput vector
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        // v[i]+v[j]+v[k]== terget ->v[j]+v[k] == target-v[i]
        int tripalte = target - v.at(i);
        //  apply two poienter
        int j = i + 1;
        int k = v.size() - 1;
        while (j < k)
        {
            int sum = v.at(j) + v.at(k);
            if (tripalte > sum)
            {
                j++;
            }
            else if (sum > tripalte)
            {
                k--;
            }
            else
            {
                ans.push_back({v[i], v[j], v[k]});
                j++;
                k--;
                while (j < k && v[j] == v[j - 1])
                    j++; // agar two consecutive term front se same ho toh
                while (j < k && v[k] == v[k + 1])
                    k--; // do back se same ho toh ak ak baar back ho jayenge
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> v;
    v.push_back(9);
    v.push_back(10);
    v.push_back(2);
    v.push_back(4);
    v.push_back(6);
    cout << "print the vector->" << endl;
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    int target = 15;
    cout << "target = " << target << endl;
    vector<vector<int>> threeSum = Find3sum(v, target);
    cout << "print three sum vector->" << endl;
    for (auto i : threeSum)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    cout << endl;
}
