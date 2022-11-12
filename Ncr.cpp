// find ncr useing function.
//ncr=n!/r!(n-r)!
#include<iostream>
using namespace std;
int factorial(int n){
    int fact=1;
    for(int i=1;i<=n;i++){
        fact=fact*i;
    }
    return fact;
}
int ncr(int n,int r){
   cout<<"enter n and r"<<endl;
   cin>>n>>r;
   int ncr= (factorial(n))/(factorial(r)*factorial(n-r));
   return ncr;
}
int main(){
    int n,r;
    int ans=ncr(n,r);
    cout<<"ncr is ="<<ans<<endl;

}