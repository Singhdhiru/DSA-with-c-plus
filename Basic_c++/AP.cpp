// find nth term of ap 
// given ap=3*n+7.if we give n= 7 the o/p is 21.
#include<iostream>
using namespace std;
int ap(int n){
    cout<<"enter nth term of ap"<<endl;
    cin>>n;
    int ans=3*n+7;
    return ans;

}
int main(){
    int n;
    int ans=ap(n);
    cout<<"nth term of ap is ="<<ans<<endl;

}