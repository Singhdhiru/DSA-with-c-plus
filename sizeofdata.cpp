#include<iostream>
using namespace std;
int main()
{
    int a=4;
    char ch='t';
    double d=1.556;
    int sizeinteger=sizeof(a);
    int sizecharacter=sizeof(ch);
    int sizedouble=sizeof(d);
    cout<<" size of an integer is:"<<sizeinteger<<" bytes"<<endl;
    cout<<"size of an character is :"<<sizecharacter<<" bytes"<<endl;
    cout<<"size of an double is :"<<sizedouble<<" bytes"<<endl;
}