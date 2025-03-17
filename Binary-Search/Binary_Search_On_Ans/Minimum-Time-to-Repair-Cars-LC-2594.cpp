#include<bits/stdc++.h>
using namespace std;

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=tOo5RX2pt0g
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-time-to-repair-cars
*/

//*Approach (Binary Search on Answer)
//T.C : O(n * log(maxRank * cars * cars))
//S.C : O(1)
class Solution {
public:
    typedef long long ll;

    bool isPossible(vector<int>& ranks, ll mid, int cars) {
        ll carsFixed = 0;
        //* Formula -> Time = Rank*N^2(n = number of car)
        //* number of car = sqrt(time/rank)
        for(int i = 0; i < ranks.size(); i++) {
            carsFixed += sqrt(mid/ranks[i]); //ignoring this
        }

        return carsFixed >= cars;

    }

    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();

        ll l = 1;
        int maxR = *max_element(begin(ranks), end(ranks));
        ll r = 1LL * maxR * cars * cars;

        ll result = -1;
        //T.C: O(n * log(maxR*cars*cars));
        while(l <= r) { //log(maxR * cars * cars)
            ll mid = l + (r-l)/2;

            if(isPossible(ranks, mid, cars)) { //O(n)
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result;
    }
};

int main() {
    // Create a test case
    vector<int> ranks = {4, 2, 3, 1};  // Ranks of mechanics
    int cars = 10;                     // Number of cars to repair
    
    // Create an instance of the Solution class
    Solution solution;
    
    // Call the repairCars method and get the result
    long long result = solution.repairCars(ranks, cars);
    
    // Display the result
    cout << "Minimum time to repair " << cars << " cars: " << result << endl;
    
    return 0;
}
