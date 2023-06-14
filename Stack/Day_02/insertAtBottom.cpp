#include<iostream>
#include<stack>
using namespace std;

stack<int> pushAtBottom(stack<int> &st, int x){
    // *base case
    if(st.empty()){
        st.push(x);
        return st ;
    }

    int num = st.top();
    st.pop();

    // * recursive call
    pushAtBottom(st, x);
    st.push(num);
    return st;
}
int main(){
    stack<int>st;
    st.push(5);
    st.push(9);
    st.push(12);
    st.push(8);
    st.push(4);
    int n = st.size();
    int x = 0;
    cout<<" size of stack before push->> "<<n<<endl;
    st = pushAtBottom(st, x);
    cout<<"size of stack after the push at bottom->>"<<st.size()<<endl;
    return 0;
}