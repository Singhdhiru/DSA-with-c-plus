#include<iostream>
#include<math.h>
using namespace std;
bool PowerOfTwo(int n){
    for(int i = 0 ; i <= 30 ; i++){
        int ans = pow(2,i);
        if(ans== n){
            return true;
        }
    }
    return false;
}
int main(){
    int n ;
    cout<<"enter the number->"<<endl;
    cin>>n;
    bool ans = PowerOfTwo(n);
    cout<<"given number convert power of two or not->"<<ans<<endl;
    return 0;
}