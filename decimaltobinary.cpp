// # convert decimal to binary .
//if we convert 1,2,3 into 123 then we appaaly ans=(ans*10)+ans'
// if we have 1,2,3 and make digit like 321 then we apply ans=(digit*10^i)+ans
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter a decimal number"<<endl;
    cin>>n;
    int ans=0;
    int i=0;
    while(n!=0)
    {
        int bit=n&1;
        ans=(bit*pow(10,i)+ans);
        n=n>>1;
        i++;
    }
    cout<<"answer is"<<ans;
}

   
        