#include <bits/stdc++.h>
using namespace std;
// *Complete Brute Force using MinHeap - TIME COMPLEXITY = O(m*n*log(k)) - TLE
//  class Solution {
//  public:
//      typedef pair<int, pair<int, int>> P;

//     vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
//         priority_queue<P, vector<P>> pq;

//         int m = nums1.size();
//         int n = nums2.size();

//         for(int i = 0; i<m; i++) {
//             for(int j = 0; j<n; j++) {

//                 int sum = nums1[i] + nums2[j];

//                 if(pq.size() < k) {
//                     pq.push({sum, {i, j}});
//                 } else if(pq.top().first > sum) {
//                     pq.pop();
//                     pq.push({sum, {i, j}});
//                 }
//             }
//         }

//         vector<vector<int>> result;

//         while(!pq.empty()) {
//             auto temp = pq.top();
//             pq.pop();

//             int i = temp.second.first;
//             int j = temp.second.second;
//             result.push_back({nums1[i], nums2[j]});
//         }

//         return result;
//     }
// };
//* Approach-2 (Slight Better approach) - O(klog(k))
class Solution
{
public:
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        priority_queue<p, vector<p>, greater<p>> pq; // Min-Heap
        int m = nums1.size();
        int n = nums2.size();
        set<pair<int, int>> st; // mark {i,j} to not entr in 2 times
        st.insert({0, 0});
        int sum = nums1[0] + nums2[0];
        pq.push({sum, {0, 0}});
        vector<vector<int>> res;
        while (k-- && pq.size() != 0)
        { // edge case agar k value is more
            // compare to pair present in both array
            auto temp = pq.top();
            pq.pop();
            int i = temp.second.first;
            int j = temp.second.second;
            res.push_back({nums1[i], nums2[j]});

            // push(i+1, j) if possible
            if (i + 1 < m && st.find({i + 1, j}) == st.end())
            {
                pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                st.insert({i + 1, j});
            }
            // push (i, j+1) if possible
            if (j + 1 < n && st.find({i, j + 1}) == st.end())
            {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                st.insert({i, j + 1});
            }
        }
        return res;
    }
};
int main(){
    vector<int>nums1 ={1,7,11};
    vector<int>nums2 = {2,4,6};
    int  k =3;
    Solution solution;
    vector<vector<int>> ans = solution.kSmallestPairs(nums1, nums2, k);
    for(auto & temp: ans){
        cout<<"("<<temp[0]<<","<<temp[1]<<")"<<endl;
    }
}