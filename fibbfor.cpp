// print fibbonic series using for loop
//output= 0,1,1,2,3,5,8,13,21
//logic:- first do number ko jodkar third number aayega
//nextnumbe=(n-1)+(n-2)
#include<iostream>
using namespace std;
int main()
{
    int n=10; //kitna tearm print karna hi 
    int a=0,b=1; //first do tearm intialize karna padega
    cout<<a<<" "<<b<<" ";
    int nextnumber;//do number jod kar third tearm banayenge
    int i=1;
    for(i;i<=10;i++)
    {
        nextnumber=a+b;
        cout<<nextnumber<<" ";
        a=b;//next number print hone ke baad a ka koiee kaam nahi hi then a ko b mai daa denge
        b=nextnumber;
    }
}