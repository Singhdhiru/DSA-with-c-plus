#include <bits/stdc++.h>
using namespace std;
class TwoStack {
    int *arr;
    int top1;
    int top2;
    int size;
public:

    //? Initialize TwoStack.
    TwoStack(int s) {
        arr = new int[s];
        top1 = -1;
        top2 = s;
        this-> size = s;
    }
    
    //? Push in stack 1.
    void push1(int num) {
        if(top2-top1>1){
            top1++;
            arr[top1]  = num;
        }
    }

    //? Push in stack 2.
    void push2(int num) {
        if(top2-top1>1){
            top2--;
            arr[top2]  = num;
        }
    }

    //? Pop from stack 1 and return popped element.
    int pop1() {
        if( top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
        {
            return -1;
        }
    }

    //? Pop from stack 2 and return popped element.
    int pop2() {
        if( top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
        {
            return -1;
        }
    }
};

int main(){
    //? create a TwoStack object with a size of 10
    TwoStack ts(10);

    // ?push some values onto stack 1
    ts.push1(5);
    ts.push1(10);
    ts.push1(15);

    // ?push some values onto stack 2
    ts.push2(20);
    ts.push2(25);
    ts.push2(30);

    //? pop some values from stack 1 and print them
    cout << "Popping values from stack 1:" <<endl;
    cout << ts.pop1() << endl;
    cout << ts.pop1() << endl;

     //* pop some values from stack 2 and print them
    cout << "Popping values from stack 2:" << endl;
    cout << ts.pop2() << endl;
    cout << ts.pop2() << endl;
    return 0;

}
