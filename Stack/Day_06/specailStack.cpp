#include<bits/stdc++.h>
using namespace std;
class SpecialStack {
    
    stack<int> s;
    int mini = INT_MAX;

    
    public:
        
    void push(int data) {
        //? first element ke liye
        if(s.empty()){
            s.push(data);
            mini = data;
        }
        //? baki element ke liye
        else{
            if(data<mini){
                s.push(2*data-mini);
                mini = data;
            }
            else{
                s.push(data);
            }
        }
    }

    int pop() {
        if(s.empty()){
            return -1;
        }
        
        int curr = s.top();
        s.pop();
        if(curr > mini) {
            return curr;
        }
        else
        {
            int prevMin = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMin;
        }
    }

    int top() {
        if(s.empty())
            return -1;
        
        int curr = s.top();
        if(curr < mini) {
            return mini;
        }
        else
        {
            return curr;
        }
    }

    bool isEmpty() {
        return s.empty();
    }

    int getMin() {
        if(s.empty())
            return -1;
        
        return mini;
    }  
};

int main() {
    SpecialStack s;

    s.push(10);
    s.push(20);
    s.push(5);
    s.push(30);

    cout << "Minimum element: " << s.getMin() << endl;
    cout << "Top element: " << s.top() << endl;

    s.pop();
    cout << "Top element after pop: " << s.top() << endl;
    cout << "Minimum element after pop: " << s.getMin() << endl;

    return 0;
}
