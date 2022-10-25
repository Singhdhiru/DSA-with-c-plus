//The call by value method of passing arguments to a function copies the actual value
// of an argument into the formal parameter of the function
#include<iostream>
using namespace std;
int dumy(int x,int y){
    x=7,y=5;
    cout<<"print number x and y"<<" "<<x<<" "<<y<<endl;
    return 0;
}
int main(){
    int x=5,y=7;
    dumy(x,y);
    cout<<"print number x and y"<<" "<<x<<" "<<y<<endl;
    return 0;

}