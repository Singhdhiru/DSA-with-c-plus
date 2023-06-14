#include <iostream>
#include <queue>
using namespace std;

int main()
{

    // ? create queue
    queue<int> q;

    // ? push element
    q.push(11);
    cout << "front of q is: " << q.front() << endl;
    q.push(15);
    cout << "front of q is: " << q.front() << endl;
    q.push(13);
    cout << "front of q is: " << q.front() << endl;
    cout << "size of queue is : " << q.size() << endl;

    // ? print the element of the queue
    cout<<"element of queue-->>";
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    

    // ? pop element
    q.pop();
    q.pop();
    q.pop();
    cout << "size of queue is : " << q.size() << endl;
    if (q.empty())
    {
        cout << "Queue is empty " << endl;
    }
    else
    {
        cout << "queue is not empty " << endl;
    }

    return 0;
}