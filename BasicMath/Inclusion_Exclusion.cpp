// * how many number between 1 and 1000 divisible by 5 or  7
#include<iostream>
using namespace std;

int divisible(int n, int a, int b){
    int c1 = n/a;
    int c2 = n/b;
    int c3 = n/(a*b);
    int Ans = c1 + c2 - c3;
    return Ans;
}
int main(){
    int number ;
    int a,b;
    cout<<"enter the number ->>";
    cin>>number;
    cout<<"dividend->>";
    cin>>a>>b;
    cout<<divisible(number, a, b)<<endl;
    return 0;
}