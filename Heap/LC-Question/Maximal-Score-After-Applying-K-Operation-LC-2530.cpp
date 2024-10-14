#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=t2tBCpzYl6w
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/maximal-score-after-applying-k-operations
*/

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long sum = 0;
        priority_queue<int> pq(begin(nums), end(nums)); //First time creation of heap "heapify" is O(n)
        //Refer - https://stackoverflow.com/questions/9755721/how-can-building-a-heap-be-on-time-complexity
        //Or you can refer NPTEL video on Heap on youtube. 
        
        while (k--) {
            int maxEl = pq.top(); // Get the largest element
            pq.pop(); // Remove it from the heap
            sum += maxEl; // Add it to the sum
            maxEl = ceil(maxEl / 3.0); // Reduce it by a third
            pq.push(maxEl); // Push it back into the heap
        }
        
        return sum; // Return the total sum of k largest elements
    }
};

int main() {
    Solution solution; // Create an instance of Solution
    vector<int> nums = {10, 20, 5, 30}; // Example input
    int k = 3; // Number of elements to consider
    
    long long result = solution.maxKelements(nums, k); // Call the method
    cout << "The maximum sum of " << k << " elements is: " << result << endl; // Output the result
    
    return 0; // Indicate successful completion
}