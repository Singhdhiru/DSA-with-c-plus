// *push efficients
#include <iostream>
#include<limits.h>
#include <stack>
using namespace std;

class Queue
{
    stack<int> st;
    stack<int> temp;

public:
    void push(int x)
    {
        // backup the element in temp stack;
        while (!this->st.empty())
        {
            temp.push(this->st.top());
            st.pop();
        }
        // original stack st is empty the we are doing push at the bottom ofthe stack
        this->st.push(x);
        // all temp elements in original stack st;
        while (!temp.empty())
        {
            this->st.push(temp.top());
            temp.pop();
        }
    }
    void pop()
    {
        if (this->st.empty())
            return;
        this->st.pop();
    }
    bool isEmpty()
    {
        return this->st.empty();
    }
    int front()
    {
        if (this->st.empty())
            return INT_MIN;
        return this->st.top();
    }
};
int main()
{
    Queue qu;
    qu.push(10);
    qu.push(20);
    qu.push(30);
    qu.pop();
    qu.push(40);
    qu.pop();
    qu.push(50);
    cout << endl;
    while (!qu.isEmpty())
    {
        cout << qu.front() << " ";
        qu.pop();
    }
    return 0;
}