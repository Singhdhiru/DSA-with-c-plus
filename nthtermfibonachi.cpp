// find nth term of fibonnachi
#include<iostream>
using namespace std;
int fibbonachi(int n){
    cout<<"enter nth term"<<endl;
    cin>>n;
    int a=0;
    int b=1;
    for(int i=2;i<n;i++){   //fobonnachi series o se begain hota hi
        int nextnum=a+b;
        a=b;
        b=nextnum;
    }
    return b;
}
int main(){
    int n;
   // int ans=fibbonachi(n);
   // cout<<"nth term of fibbonachi series"<<" "<<ans<<endl;
   cout<<fibbonachi(n)<<endl;

}
