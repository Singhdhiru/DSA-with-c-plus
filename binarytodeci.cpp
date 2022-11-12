// binary to decimal conversion.
#include<iostream>
#include<math.h>
using namespace std;
int main()
{

    int n;
    cout<<"enter decimal number for conversion"<<endl;
    cin>>n;
    int i=0,ans=0;
    while(n!=0)
    {
        int digit=n%10;//chuki input decimal mai per ham ishe binary samjenge
        if(digit==1){
            ans=ans+pow(2,i);//chuki digit=0 aata hi toh toh ignor kar dnge 

        }
        n=n/10;
        i++; 
    
    }
    cout<<"decimal"<<" "<<ans;
}