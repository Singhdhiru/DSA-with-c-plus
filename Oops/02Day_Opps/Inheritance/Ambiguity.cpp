#include <iostream>
using namespace std;

class A
{
public:
    void func()
    {
        cout << " I am A" << endl;
    }
};

class B
{
public:
    void func()
    {
        cout << " I am B" << endl;
    }
};

class C : public A, public B
{
};

int main()
{

    C obj;
    //* obj.func();  ambiguity occur in this line

    // * resolve ambiguity using scope of resolution operator(::)
    obj.A::func();
    obj.B::func();

    return 0;
}