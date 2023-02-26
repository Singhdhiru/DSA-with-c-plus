#include <iostream>
using namespace std;
int main()
{

    int arr[10] = {1, 2, 3, 4, 5, 6, 0, 0, 0, 0};
    cout << "address of 1st index element->>" << arr << endl;
    cout << "alternative way->>" << &arr[0] << endl;
    cout << "element of 1st index--->" << arr[1] << endl;

    cout << *arr << endl;       //* fecth value at 0th index
    cout << *arr + 1 << endl;   // * fetches value at 1st index
    cout << *(arr + 1) << endl; //* fethches value at 1st index
    cout << (*arr) + 1 << endl; //* fethes value at 1st index

    int i = 4;
    cout << i[arr] << endl; // * value at ith index

    int temp[10] = {1, 2};
    cout << sizeof(temp) << endl;             //* size of array->>40
    cout << " 1st " << sizeof(*temp) << endl; //* size of 0th index element->>4
    cout << " 2nd " << sizeof(&temp) << endl; //*size of address of first element->>4

    //* pointer array A in C++ is an array of pointer variables that stores multiple addresses of other variables. The size of a pointer array in C++ depends on the size of the pointer type, which is usually 4 bytes for a 32-bit system or 8 bytes for a 64-bit system.

    int *ptr = &temp[0];
    cout << sizeof(ptr) << endl;  //* size of pointer->>4
    cout << sizeof(*ptr) << endl; //* size first element in temp->>4
    cout << sizeof(&ptr) << endl; // * size of pointer address->>4

    int a[20] = {1, 2, 3, 5};
    cout << " ->" << &a[0] << endl; //* addres of first index
    cout << &a << endl;
    cout << a << endl;

    int *p = &a[0];
    cout << p << endl;
    cout << *p << endl;
    cout << "-> " << &p << endl; //* address of pointer

    int arr[10];

    // ERROR
    // arr = arr+1;

    int *ptr = &arr[0];
    cout << ptr << endl;
    ptr = ptr + 1;
    cout << ptr << endl;
    return 0;
}