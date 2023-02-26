// *Catalan numbers are defined as a mathematical sequence that consists of positive integers, which can be used to find the number of possibilities of various combinations. 

//* The nth term in the sequence denoted Cn, is found in the following formula: \frac{(2n)!}{(n + 1)! n!)}

#include<bits/stdc++.h>
using namespace std;

int catalan_number(int n){
    if(n<=1){
        return 1;
    }
    int res = 0;
    for(int i=0; i<n; i++){
        res+= catalan_number(i)*catalan_number(n-i-1);
    }
    return res;
}
int main(){
    for(int i=0; i<10; i++){
        cout<<catalan_number(i)<<" ";
    }
    cout<<endl;
    return 0;
}