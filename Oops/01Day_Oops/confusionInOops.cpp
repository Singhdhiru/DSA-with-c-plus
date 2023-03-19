#include<iostream>
using namespace std;

class MyClass {
public:
    //* Public member variables and functions
    char x;
    // void printX() {
    //     cout << x <<endl;
    // }
private:
    // *Private member variables and functions
    int y;
};

int main(){
    cout<<"print the size of class-->>"<<sizeof(MyClass)<<endl; //* give size 8 why??????????
    return 0;
}
// * learn about padding and greedy alignments