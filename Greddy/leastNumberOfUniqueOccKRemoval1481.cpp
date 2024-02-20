#include <bits/stdc++.h>
using namespace std;
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=O5v9Tqv2ZDA
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals
*/
// Approach-1 (Using Map and Sorting)
// T.C : O(nlogn)
// S.C : O(n)
int findLeastNumOfUniqueInts(vector<int> &arr, int k)
{
    unordered_map<int, int> mp;

    for (int &x : arr)
    {
        mp[x]++;
    }

    vector<int> freq;

    for (auto &it : mp)
    {
        freq.push_back(it.second);
    }

    sort(begin(freq), end(freq));

    for (int i = 0; i < freq.size(); i++)
    {

        k -= freq[i];

        if (k < 0)
        {
            return freq.size() - i;
        }
    }

    return 0; // All were removed
}
// Approach-2 (Using min-heap)
// T.C : O(nlogn)
// S.C : O(n)
int findLeastNumOfUniqueInts_PQ(vector<int> &arr, int k)
{
    unordered_map<int, int> mp;

    for (int &x : arr)
    {
        mp[x]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq; // min-heap
    for (auto &it : mp)
    {
        pq.push(it.second);
    }

    while (!pq.empty())
    {

        k -= pq.top();

        if (k < 0)
        {
            return pq.size();
        }

        pq.pop();
    }

    return 0; // All were removed
}

int main()
{
    vector<int> nums = {5, 5, 1, 6};
    int ans = findLeastNumOfUniqueInts(nums, 1);
    cout<<"Lest number of unique occ after k removal->> "<<ans;
    return 0;
}