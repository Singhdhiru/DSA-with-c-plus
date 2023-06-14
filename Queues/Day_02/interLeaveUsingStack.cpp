// C++ program to interleave the first half of the queue
// with the second half
#include <bits/stdc++.h>
using namespace std;

// Function to interleave the queue
void interLeaveQueue(queue<int> &q)
{
    //  we are follow this step
    // step 1
    stack<int> s;
    int n = q.size() / 2;
    for (int i = 0; i < n; i++)
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    // step 2:
    while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);
    }

    // step 3:
    for(int i=0; i<n; i++){
        int val = q.front();
        q.pop();
        q.push(val);
    }

    // step 4:
    for(int i=0; i<n; i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }

    // step 5:
    while (!s.empty())
    {
        int val = s.top();
        s.pop();
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
