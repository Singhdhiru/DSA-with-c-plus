#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int element)
{
    // ?base case
    if (s.empty())
    {
        s.push(element);
        return;
    }

    int num = s.top();
    s.pop();

    // * recursive call
    insertAtBottom(s, element);
    s.push(num);
}
void reverseStack(stack<int> &s)
{
    // ?base case
    if (s.empty())
    {
        return;
    }

    // ? top ko bacha lenge
    int num = s.top();
    s.pop();

    // ?recursive call
    reverseStack(s);

    // ? top ko bottom mai insert kr denge
    insertAtBottom(s, num);
}
int main()
{
    stack<int> s;
    s.push(3);
    s.push(4);
    s.push(7);
    s.push(9);

    cout << "Stack before reversal: ";
    stack<int> temp = s;
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    reverseStack(s);
    cout << "Stack after reversal: ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}
