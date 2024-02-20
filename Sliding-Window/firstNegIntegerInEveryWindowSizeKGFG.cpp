#include <bits/stdc++.h>
using namespace std;
/*
GFG     :  https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

YT      : https://www.youtube.com/watch?v=-uc7OCrjp8g&list=PLpIkg8OmuX-J2Ivo9YdY7bRDstPPTVGvN&index=4
*/
//?  TC     : Since each element is processed once, the time complexity is O(N).
//   SC     : the space complexity is O(K) athe space complexity is O(K) 
vector<long long> printFirstNegativeInteger(vector<long long> A,long long int N, long long int K)
{
    vector<long long> res;
    queue<long long> deq;
    int i = 0;
    int j = 0;
    while (j < N)
    {
        if (A[j] < 0)
        {
            deq.push(A[j]);
        }
        // ? Check Window size 
        if (j - i + 1 == K)
        {
            //? Koiee neg element nahi mila hi
            if (deq.empty())
            {
                res.push_back(0);
            }
            else
            {
                res.push_back(deq.front());
            }
            // ? agar queue mai front mai neg element hi use hta do nahi again push ho jayega
            if (A[i] < 0)
            {
                deq.pop();
            }
            i++;
        }
        j++;
    }
    return res;
}
int main()
{
    vector<long long> nums = {-8, 2, 3, -6, 10};
    int n = nums.size();
    vector<long long> res = printFirstNegativeInteger(nums, n, 2);
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}