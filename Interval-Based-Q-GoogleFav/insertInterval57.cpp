#include <bits/stdc++.h>
using namespace std;
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=XXaVIDIbUn4
    Company Tags                : Google, Twitter, Microsoft, Apple, Amazon
    Leetcode Link               : https://leetcode.com/problems/insert-interval/
*/
// Approach-1 (TLE)
// T.C : (O(n^2))
// S.C : O(1)
vector<vector<int>> insert_bruteForce(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    int i = 0;

    while (i < intervals.size())
    {
        if (intervals[i][1] < newInterval[0])
            i++;
        else if (intervals[i][0] > newInterval[1])
        {
            intervals.insert(intervals.begin() + i, newInterval);
            return intervals;
        }
        else
        {
            // Overlap : merge them
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            intervals.erase(intervals.begin() + i);
        }
    }

    intervals.push_back(newInterval);
    return intervals;
}
// Approach-2
// T.C : O(n)
// S.C : O(n) for result
vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    int i = 0;
    vector<vector<int>> result;

    while (i < intervals.size()) // her baar interval ka size chhota hoga
    {
        // * jo newInterval hi o overllap nahi kar raha hi usko ans mai daal do
        if (intervals[i][1] < newInterval[0])  // ending[i] < newInterval[0]->starting
        {
            result.push_back(intervals[i]);
        }
        else if (intervals[i][0] > newInterval[1])
        {
            break;
        }
        else
        {
            // Overlap : merge them
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
        i++;
    }

    result.push_back(newInterval);
    // * mai jo interval bacha hi usko dall do
    while (i < intervals.size())
    {
        result.push_back(intervals[i]);
        i++;
    }
    return result;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};
    vector<vector<int>> vec = insert(intervals, newInterval);
    cout<<"Insert Interval ->> ";
    for (auto &it : vec)
    {
        cout << "[" << it[0] << " " << it[1] << "]"<< " ";
    }
    cout << endl;
}
