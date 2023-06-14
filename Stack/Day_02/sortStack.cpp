#include<iostream>
#include<stack>
using namespace std;

void sortedInsert(stack<int> &s, int element){
    // ?base case
    if(s.empty() || (!s.empty() && s.top()<element) ){ //* top ko compare karne se pahle check kr lenge empty toh nahi hi
        s.push(element);
        return ;
    }

    int n = s.top();
    s.pop();

    // ? recursive call
    sortedInsert(s, element);
    s.push(n);
}
void sortStack(stack<int>& s){
    // ? base case
    if(s.empty()){
        return ;
    }

    int num = s.top();
    s.pop();

    // ?recursive call
    sortStack(s);

    sortedInsert(s, num);
}
int main(){
    stack<int> s;
    s.push(8);
    s.push(7);
    s.push(1);
    s.push(10);
    s.push(0);
    cout<<"stack before sorting: ";
    stack<int>temp = s;
    while(!temp.empty()){
        cout<<temp.top()<<" ";
        temp.pop();
    }
    cout<<endl;

    sortStack(s);
    cout<<"stack after sorting: ";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}