#include <bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> &q, int k)
{
    // algo:
    // first k element stack me daaldo  and queue se hatado
    //  k element stack se nikalke wapas queue me daalde
    //  fer queue k (n-k) starting k elements, wapas queue me daalde

    stack<int> s;
    for (int i = 0; i < k; i++)
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }
    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        q.push(val);
    }

    int t = q.size() - k;

    while (t--)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }

    return q;
}
int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);

    int k = 5;

    queue<int> modified_q = modifyQueue(q, k);

    while (!modified_q.empty())
    {
        cout << modified_q.front() << " ";
        modified_q.pop();
    }

    return 0;
}