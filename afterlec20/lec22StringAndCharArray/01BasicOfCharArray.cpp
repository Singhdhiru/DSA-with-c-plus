#include<iostream>
using namespace std;
int main(){
    // intailize char array
    char my_name[100] = "apple" ;
    cout<<my_name << endl;
    // take char array as a input
    int n ;
    cout<<"enter the size of char array"<<endl;
    cin>>n ;
    char name[n];
    cin>>name ;
    cout<<name <<endl;
    // access any char array element
    cout<<my_name[4]<<endl;
    return 0;


}