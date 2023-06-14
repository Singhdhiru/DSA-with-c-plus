// #include <bits/stdc++.h>
// using namespace std;

// queue<int> queueRev(queue<int> &q)
// {
//     stack<int> s;

//     while (!q.empty())
//     {
//         int element = q.front();
//         q.pop();
//         s.push(element);
//     }

//     while (!s.empty())
//     {
//         int element = s.top();
//         s.pop();
//         q.push(element);
//     }
//     return q;
// }
// int main()
// {
//     queue<int> q;
//     q.push(2);
//     q.push(5);
//     q.push(6);
//     q.push(0);
//     q.push(8);
//     q.push(7);
//     q.push(9);
//     // ? print the element of the queue
//     cout << "element of queue-->>";
//     while (!q.empty())
//     {
//         cout << q.front() << " ";
//         q.pop();
//     }
//     cout << endl;

//     //? reverse the queue
//     queue<int> reversedQueue = queueRev(q);

//     //? print the elements of the reversed queue
//     cout << "Elements of the reversed queue: ";
//     while (!reversedQueue.empty())
//     {
//         cout << reversedQueue.front() << " ";
//         reversedQueue.pop();
//     }
//     cout << endl;

//     return 0;

// }

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void queueRev(queue<int> &q)
{
    stack<int> s;

    while (!q.empty())
    {
        int element = q.front();
        q.pop();
        s.push(element);
    }

    while (!s.empty())
    {
        int element = s.top();
        s.pop();
        q.push(element);
    }
}

int main()
{
    queue<int> q;
    q.push(2);
    q.push(5);
    q.push(6);
    q.push(0);
    q.push(8);
    q.push(7);
    q.push(9);
    // print the elements of the queue
    // cout << "Elements of the queue: ";
    // while (!q.empty())
    // {
    //     cout << q.front() << " ";
    //     q.pop();
    // }
    // cout << endl;

    // reverse the queue
    queueRev(q);

    // print the elements of the reversed queue
    cout << "Elements of the reversed queue: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
