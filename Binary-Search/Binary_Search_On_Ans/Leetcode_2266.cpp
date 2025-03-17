//*Leetcode Link : https://leetcode.com/problems/maximum-candies-allocated-to-k-children
#include<bits/stdc++.h>
using namespace std;

//Approach-1 (Brute Force)
//T.C : O(n * maxC), maxC = maximum candy value
//S.C : O(1)
class Solution1 {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();

        int maxC = 0;
        int total = 0;
        for(int i = 0; i < n; i++) {
            total += candies[i];
            maxC = max(maxC, candies[i]);
        }

        if(total < k) {
            return 0;
        }


        //Brute force try from maxC till 1
        for(int c = maxC; c >= 1; c--) {
            long long count = 0;

            for(int i = 0; i < candies.size(); i++) {
                count += candies[i]/c; //how many children can get c candies from this pile
            }
            if(count >= k) {
                return c;
            }
        }

        return 0;
    }
};



//Approach-2 (Binary Search on answer)
//T.C : O(n * log(maxC)), maxC = maximum candy value
//S.C : O(1)
class Solution {
public:
    bool canDistr(vector<int>& candies, int mid, long long k) {
        int n = candies.size();

        for(int i = 0; i < n; i++) {
            k -= candies[i]/mid;

            if(k <= 0) { //all children got mid candies
                return true; //Early return
            }
        }

        return k <= 0; //all children got the mid candies
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();

        int maxC = 0;
        long long total = 0;
        for(int i = 0; i < n; i++) {
            total += candies[i];
            maxC = max(maxC, candies[i]);
        }

        if(total < k) {
            return 0;
        }

        int l = 1;
        int r = maxC;
        int result = 0;
        while(l <= r) {
            int mid = l + (r-l)/2;

            if(canDistr(candies, mid, k)) {
                result = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        return result;
    }
};

int main() {
    // Test case
    vector<int> candies = {5, 8, 6};
    long long k = 3;
    
    // Testing the first approach (Brute Force)
    Solution1 solution1;
    int result1 = solution1.maximumCandies(candies, k);
    cout << "Maximum candies using Brute Force: " << result1 << endl;
    
    // Testing the second approach (Binary Search)
    // Since both classes are named "Solution", we need to comment out one when using the other
    // or rename them to Solution1 and Solution2
    // Solution solution2;
    // int result2 = solution2.maximumCandies(candies, k);
    // cout << "Maximum candies using Binary Search: " << result2 << endl;
    
    return 0;
}