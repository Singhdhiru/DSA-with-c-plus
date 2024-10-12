#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
//*Approach (Simply sorting and using heap)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // Sort the intervals based on their start points
        sort(begin(intervals), end(intervals));
        priority_queue<int, vector<int>, greater<int>> pq; // stores end points of groups

        for (vector<int>& interval : intervals) {
            int start = interval[0];
            int end = interval[1];

            // If the earliest ending group can be merged with the current interval
            if (!pq.empty() && pq.top() < start) {
                pq.pop(); // Remove the group as it can be merged
            }
            pq.push(end); // Add the current interval's end point to the group
        }
        
        return pq.size(); // The size of the priority queue represents the number of groups needed
    }
};

int main() {
    Solution solution;
    
    // Test data: list of intervals
    vector<vector<int>> intervals = {
        {1, 3},
        {2, 5},
        {4, 6}
    };
    
    // Calculate minimum number of groups
    int result = solution.minGroups(intervals);
    
    // Output the result
    cout << "Minimum number of groups: " << result << endl;

    return 0;
}