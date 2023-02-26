#include <iostream>
using namespace std;

int main()
{

    int num = 5;

    cout << num << endl;

    // address of Operator - &

    cout << " address of num is " << &num << endl;
    // * intialization of pointers and dealarring
    int *ptr = &num;

    cout << "Address is : " << ptr << endl;
    cout << "value is : " << *ptr << endl;

// * double pointers declaring
    double d = 4.3;
    double *p2 = &d;

    cout << "Address is : " << p2 << endl;
    cout << "value is : " << *p2 << endl;

    cout << " size of integer is " << sizeof(num) << endl;   //* sizeof()->>> find the size of data type
    cout << " size of pointer is " << sizeof(ptr) << endl;
    cout << " size of pointer is " << sizeof(p2) << endl;

    return 0;
}