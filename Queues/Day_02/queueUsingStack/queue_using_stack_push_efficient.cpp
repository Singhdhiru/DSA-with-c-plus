// *push efficients 
#include<iostream>
#include<stack>
using namespace std;

class Queue{
    stack<int>st;
    stack<int>temp;
    public:
    /*
    T.E->O(1)
    */
    void push(int x){
        this->st.push(x);
    }
    /*
    T.E->O(n)
    */
    void pop(){
        // stack<int>temp;
        while(this->st.size()>1){
            this->temp.push(st.top());
            this->st.pop();
        }
        // now stack size is 1 and we are at the bottom element
        this->st.pop();
        while(!temp.empty()){
            this->st.push(temp.top());
            temp.pop();
        }
    }
    bool isEmpty(){
        return this->st.empty();
    }
    /*
    T.E->O(n)
    */
    int front(){
        if (this->st.empty()) {
            return -1; // Return a default value when the queue is empty
        }
        while(this->st.size()>1){
            this->temp.push(st.top());
            this->st.pop();
        }
        // now stack size is 1 and we are at the bottom element
        int result = st.top();
        while(!temp.empty()){
            this->st.push(temp.top());
            temp.pop();
        }
        return result;
    }
};
int main(){
    Queue qu;
    qu.push(10);
    qu.push(20);
    qu.push(30);
    qu.pop();
    qu.push(40);
    qu.push(50);
    cout<<endl;
    while (!qu.isEmpty()) {
        cout <<qu.front() << " ";
        qu.pop();
    }
    return 0;
}