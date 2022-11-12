//subtract the product and sum of digit of an integer
//this is worng answer
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    int product=1;
    int sum=0;
    while(n)
    {
        product=product*(n%10);
        sum=sum+(n%10);
        n=n/10;


    }
    int result;
    result=product-sum;
}