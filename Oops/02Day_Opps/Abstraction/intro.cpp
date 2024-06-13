#include<iostream>
using namespace std;
// * understand the implementation of Abtraction in c++
class Abstraction{
    int a;
    int b;
    public:
    void set(int x, int y){
        a = x;
        b = y;
    }
    void print(){
        cout<<"value of a->"<<a<<endl;
        cout<<"value of b->"<<b<<endl;
    }
};
int main(){
    // * create obj
    Abstraction obj;
    obj.set(10, 20);
    obj.print();

}
// * https://stackoverflow.com/questions/742341/difference-between-abstraction-and-encapsulation 