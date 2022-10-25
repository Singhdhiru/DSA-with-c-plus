//sum of n number using while loop(in childhood formula=n(a+l)/2)
#include<iostream>
using namespace std;
int main()
{
    int i=1,sum=0;
    int n;
    cout<<"enter number"<<endl;
    cin>>n;
    while(i<=n)
    {
        sum=sum+i;
        i=i+1;
    }
    cout<<"print sum="<<sum<<endl;
}