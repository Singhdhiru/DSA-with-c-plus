#include <iostream>
using namespace std;
int main()
{

    //* wild pointer
    int *ptr; //*only declare
    cout << ptr << " " << *ptr << endl;
    cout << endl;

    //* NULL pointers
    int *ptr1 = NULL;
    int *p1 = 0;
    int *p2 = '\0';
    cout << ptr1 << " " << p1 << " " << p2 << endl;
    cout << endl;

    //*Dangling pointers
    int *ptr2 = NULL;
    {
        int x = 10;
        ptr2 = &x;
    }
    cout<<ptr2<<endl;

    
    return 0;
}