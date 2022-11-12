// find setbit of two number and add this number.
//like i/p 2=10 ,3=110
//o/p total number of set bit is equal to 3.
#include<iostream>
using namespace std;
int setbitsB(int b){
     int count=0;
    while(b!=0){
        if(b&1){
            count++;
        }
        b=b>>1;
    }
    return count;


}
int setbitsA(int a){
    int count=0;
    while(a!=0){
        if(a&1){
            count++;
        }
        a=a>>1;
    }
    return count;
}
int main(){
    int a,b;
    cin>>a>>b;
    int ans1 = setbitsA(a);
    int ans2=setbitsB(b);
    int ans=ans1+ans2;
    cout<<ans<<endl;
}