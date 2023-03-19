#include <iostream>
using namespace std;
//*Hierarchical Inheritance
class A
{

public:
    void func1()
    {
        cout << "Inside Funcion 1" << endl;
    }
};

class B : public A
{
public:
    void func2()
    {
        cout << "Inside Funcion 2" << endl;
    }
};

class C : public A
{
public:
    void func3()
    {
        cout << "Inside Funcion 3" << endl;
    }
};

// * multilevel inheritance
class F
{
public:
    void Func4()
    {
        cout << "inside function 4" << endl;
    }
};

// * make hybrid inheritance->> using multiple and hierarchical inheritance
// * hybrid inheritance
class Hybrid : public A, public F
{
    public:
    void func6(){
        cout<<"inside function 6"<<endl;
    }
};

int main()
{

    Hybrid obj1;
    obj1.func6();
    obj1.func1();
    obj1.Func4();

    return 0;
}