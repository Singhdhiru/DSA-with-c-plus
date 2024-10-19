#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// * Approach-> Using maxHeap
// T.C-> O(nlogk)
// S.C->O(k) -> k = k closest point
class Solution
{
public:
    // find the distnace from the orign
    int getDistanceFromOrigin(vector<int> point)
    {
        return point[0] * point[0] + point[1] * point[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> ans;
        //* pq store-> {distance(1,3), vector<int>point = {1,3}}
        // {int , vector<int> }
        priority_queue<pair<int, vector<int>>> pq; // origin se big distance ko top per rakhega
        for (vector<int> &point : points)
        {
            pq.push({getDistanceFromOrigin(point), point});
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
    vector<vector<int>> point = sol.kClosest(points, 2);

    for (vector<int> &it : point)
    {
        cout << it[0] << " " << it[1] << endl;
    }

    return 0;
}
