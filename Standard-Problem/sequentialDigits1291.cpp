#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=E5XFO3-6xe4
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/sequential-digits/
*/

/************************************************************ C++ ******************************************************************/
//?Approach-1 (Using workaround)->> are are bhai bhai approach
// T.C : O(1)
// S.C : O(1)
vector<int> sequentialDigits_simpleApproach(int low, int high)
{
    vector<int> allPossible = {12, 23, 34, 45, 56, 67, 78, 89,
                               123, 234, 345, 456, 567, 678, 789,
                               1234, 2345, 3456, 4567, 5678, 6789,
                               12345, 23456, 34567, 45678, 56789,
                               123456, 234567, 345678, 456789,
                               1234567, 2345678, 3456789,
                               12345678, 23456789,
                               123456789};

    vector<int> result;

    int n = allPossible.size();

    for (int i = 0; i < n; i++)
    {
        if (allPossible[i] < low)
            continue;

        if (allPossible[i] > high)
            break;

        result.push_back(allPossible[i]);
    }
    return result;
}
//?Approach-1 (Using simple BFS)
// T.C : O(N), where N is the number of valid sequential digits in the specified range.
// S.C : O(N), where N is the number of valid sequential digits in the specified range. (queue size)
vector<int> sequentialDigits_bfs(int low, int high)
{
    queue<int> que;
    for (int i = 1; i <= 8; i++)
    {
        que.push(i);
    }

    vector<int> result;

    while (!que.empty())
    {
        int temp = que.front();
        que.pop();

        if (temp >= low && temp <= high)
        {
            result.push_back(temp);
        }

        int last_digit = temp % 10;
        if (last_digit + 1 <= 9)
        {
            que.push(temp * 10 + (last_digit + 1));
        }
    }

    return result;
}
//? APPROACH->> 03
// using recurssion
vector<int> ans;
void dfs(int low, int high, int i, int num)
{

    // lies in range
    if (num >= low and num <= high)
        ans.push_back(num);

    if (num > high or i > 9)
        return;

    dfs(low, high, i + 1, num * 10 + i);
}
vector<int> sequentialDigits(int low, int high)
{
    for (int i = 1; i <= 9; i++)
        dfs(low, high, i, 0);
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<int> ans = sequentialDigits(100, 300);
    for (auto &it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}