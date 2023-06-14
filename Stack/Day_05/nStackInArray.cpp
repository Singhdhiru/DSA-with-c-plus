#include <bits/stdc++.h>
using namespace std;

class NStack
{
    int *arr;
    int *top;
    int *next;

    int n, s;

    int freespot;

public:
    //? Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        //? top initialise
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }

        // ?next initialise
        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }
        // ?update last index value to -1
        next[s - 1] = -1;

        // ?initialise freespot
        freespot = 0;
    }

    //? Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // ?check for overflow
        if (freespot == -1)
        {
            return false;
        }

        //? find index
        int index = freespot;

        //? insert element into array
        arr[index] = x;

        //? update freespot
        freespot = next[index];

        // ?update next;
        next[index] = top[m - 1];

        //? update top
        top[m - 1] = index;

        return true;
    }

    //? Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // ?check underflow condition
        if (top[m - 1] == -1)
        {
            return -1;
        }

        int index = top[m - 1];

        top[m - 1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
};

int main()
{
    //? Create an object of NStack with 3 stacks of size 10 each.
    NStack nstack(3, 10);

    //? Push some elements into the stacks.
    nstack.push(5, 1);
    nstack.push(10, 2);
    nstack.push(15, 3);

    //? Pop an element from the stacks.
    int popped_element = nstack.pop(1);
    if (popped_element != -1)
    {
        cout << "Popped element from stack 1: " << popped_element << endl;
    }
    else
    {
        cout << "Stack 1 is empty." << endl;
    }

    //? Push some more elements into the stacks.
    nstack.push(20, 1);
    nstack.push(25, 2);
    nstack.push(30, 3);

    //? Pop some more elements from the stacks.
    popped_element = nstack.pop(2);
    if (popped_element != -1)
    {
        cout << "Popped element from stack 2: " << popped_element << endl;
    }
    else
    {
        cout << "Stack 2 is empty." << endl;
    }

    popped_element = nstack.pop(3);
    if (popped_element != -1)
    {
        cout << "Popped element from stack 3: " << popped_element << endl;
    }
    else
    {
        cout << "Stack 3 is empty." << endl;
    }

    //? Pop from an empty stack.
    popped_element = nstack.pop(1);
    if (popped_element != -1)
    {
        cout << "Popped element from stack 1: " << popped_element << endl;
    }
    else
    {
        cout << "Stack 1 is empty." << endl;
    }

    return 0;
}
