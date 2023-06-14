#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindoes(vector<int> &v, int k)
{
    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < v.size(); i++)
    {
        if (!dq.empty() && dq.front() == i - k)
        {
            dq.pop_front();
        }
        while (!dq.empty() && v[dq.back()] < v[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k - 1)
            ans.push_back(v[dq.front()]);
    }
    return ans;
}
int main()
{
    vector<int> v = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> finalRes = maxSlidingWindoes(v, k);
    for (int i = 0; i < finalRes.size(); i++)
    {
        cout << finalRes[i] << " ";
    }
    cout << endl;
    return 0;
}
