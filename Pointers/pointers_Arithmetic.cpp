#include<iostream>
using namespace std;
int main(){
    int x, y ;// declare x and y , so, x and y has garbege value
    cin>>x>>y; // taking input
    
    int *ptrx = &x ; // &x fethes the address of x and than  store in ptrx
    int *ptry = &y; // &y fethes the address of y and than  store in ptrx
    int result ;
    int *ptr_result = &result;
    
    *ptr_result = *ptrx + *ptry;

    cout<<"reult->>>"<<result<<endl;
    return 0;
}