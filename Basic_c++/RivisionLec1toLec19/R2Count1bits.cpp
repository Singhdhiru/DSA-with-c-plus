// Leet code problem-> count number of 1 bits
#include<iostream>
using namespace std;
int CountSetbits(int n){
    int count = 0 ;
    while(n!=0){
        if(n&1){
            count++;
        }
        n = n>>1;
    }
    return count;
      
}
int main(){
    int n ;
    cout<<"enter a integer"<<endl;
    cin>>n;
    int Ans = CountSetbits(n);
    cout<<"total number of setbits->"<<Ans<<endl;
    return 0;

}