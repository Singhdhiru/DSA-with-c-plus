#include<iostream>
#include<stack>
using namespace std;

void deleteMiddle(stack<int>& st, int count, int size){

    // ? base case
    if(count == size/2){
        cout<<" deleted element-->> "<<st.top()<<endl;
        st.pop();
        return ;
    }

    // * top ko store kr lenge
    int num = st.top();
    st.pop();

    // ? recursive call
    deleteMiddle(st, count+1, size);

    // * top ko delete kiya tha phir use push kr lo
    st.push(num);
}
int main(){
    stack<int>st;
    st.push(5);
    st.push(9);
    st.push(12);
    st.push(8);
    st.push(4);
    int n = st.size();
    int count = 0;
    deleteMiddle(st, count, n);
    return 0;
}