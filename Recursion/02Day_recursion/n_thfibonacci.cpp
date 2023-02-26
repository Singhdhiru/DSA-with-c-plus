// * nth fibonacci using recursion
#include<iostream>
using namespace std;

int nth_fibonacci(int n){
    if(n == 0){  //* base case
        return 0;
    }
    if(n == 1){ //* base case
        return 1;
    }
    return nth_fibonacci(n-1) + nth_fibonacci(n-2);
}
int main(){
    int n;
    cout<<"enter the nth term->>";
    cin>>n;
    int ans = nth_fibonacci(n);
    cout<<ans<<endl;
    return 0;
}