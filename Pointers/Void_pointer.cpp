#include<iostream>
using namespace std;
int main(){
    float f = 10.2;
    int x =10;
    void *ptr = &f;
    ptr = &x;

    // ! we cant do it b/c compler don't understand what are give 
    //! cout<<*ptr<<endl;

    //* we can use typingcasting
    int *integerPointer = (int *)ptr;
    cout<<*integerPointer<<endl;


}