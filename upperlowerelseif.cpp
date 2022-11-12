//using elseif codition for cheking upper and lower case
#include<iostream>
using namespace std;
int main()
{
    char ch;
    cout<<"enter world"<<endl;
    cin>>ch;
    if(ch>'A' && ch<'Z')
    {
        cout<<"this word is lies in upper case"<<endl;
    
    }
    if(ch>'a' && ch<'z')
    {
        cout<<"this word is lies in lower case"<<endl;

    }
    if(ch>'1' && ch<'9')
    cout<<"this word lies in numeric case"<<endl;



}
