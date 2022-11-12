// scope of variable or how to define variable
#include<iostream>
using namespace std;
int main()
{
    int a=5;//esh ye ko if wale mai access kar sakte aur bhi kahi accesss kar sakte hi
    cout<<a<<endl;
    if(true)
    {
        a=4;//ye wala a shirf if block ke liye valid esh ye if block ke baad access nahi kar sakye hi
        cout<<a<<endl;
        
    }

}