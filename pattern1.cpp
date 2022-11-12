//using while loop print pattren problem
#include<iostream>
using namespace std;
int main()
{
    int i=1,n;
    int j=1;
    cout<<"enter number of row"<<endl;
    cin>>n;
    for(i;i<=n;i++)
    {
        for(j;j<=n;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}   