#include<iostream>
using namespace std;
// Implement abstarct class
class Base{
    int x = 0;
    public:
    //* assign virtual function is equal to 0;
    virtual void show() = 0;
};
// create derived class
class Derived : public Base{
    public:
    void show(){
        cout<<"Virtual function ko Drive class mai implement karna hota hi"<<endl;
    }
};

int main(){
    // creating a pointer of type
    // Base pointing to an object
    // of type Derived
    Base* bp = new Derived();

    // calling the show() function using the
    // pointer
    bp->show();

    return 0;
}