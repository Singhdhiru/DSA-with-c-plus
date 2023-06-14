#include <bits/stdc++.h>
using namespace std;

void interLeaveQueue(queue<int> &q)
{
    int halfSize = q.size() / 2;
    queue<int> newQ;
    int n = q.size();
    for (int i = 0; i < n / 2; i++)
    {
        int val = q.front();
        q.pop();
        newQ.push(val);
    }
    while (!newQ.empty())
    {
        int val = newQ.front();
        newQ.pop();
        q.push(val);

        int val2 = q.front();
        q.pop();
        q.push(val2);
    }
}
int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    interLeaveQueue(q);
    int length = q.size();
    for (int i = 0; i < length; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}