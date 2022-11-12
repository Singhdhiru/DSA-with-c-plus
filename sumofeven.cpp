//sum of even number using while loop
#include<iostream>
using namespace std;
int main()
{
    int i=2,n,sum=0;
    cout<<"enter total number"<<endl;
    cin>>n;
    while(i<n)
    {
        sum=sum+i;
        i=i+2;
    }
    cout<<"total sum of even number"<<sum<<endl;

}