// *push efficients 
#include<iostream>
#include<queue>
using namespace std;

class Stack{
    queue<int>qu;
    queue<int>temp;
    int size;
    public:
    Stack(){
        size  = 0;
    }
    /*
    T.E->O(1)
    */
    void push(int x){
        this->qu.push(x);
        size++;
    }
    /*
    T.E->O(n)
    */
    void pop(){
        while(this->qu.size()>1){
            temp.push(this->qu.front());
            qu.pop();
        }
        // now size of queue is 1 and now we are at back of queue
        qu.pop();
        while(!temp.empty()){
            qu.push(temp.front());
            temp.pop();
        }
        size--;
    }
    bool isEmpty(){
        return this->qu.size();
    }
    /*
    T.E->O(n)
    */
    int top(){
        if(this->qu.empty()) return -1;
        while(this->qu.size()>1){
            temp.push(this->qu.front());
            qu.pop();
        }
        // now size of queue is 1 and now we are at back of queue
        int result = qu.front();
        qu.pop();
        while(!temp.empty()){
            qu.push(temp.front());
            temp.pop();
        }
        return result;
    }
    int getSize(){
        return this->size;
    }
};
int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.pop();
    st.push(30);
    st.push(40);
    st.pop();
    st.push(50);
    // st.pop();
    // while(!st.isEmpty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }
    cout<<"stack top:"<<st.top()<<endl;
    cout<<"size of stack:"<<st.getSize()<<endl;
    return 0;
}