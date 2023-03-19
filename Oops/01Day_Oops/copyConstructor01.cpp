#include <iostream>
using namespace std;

class MyClass
{
    int x, y;

public:
    MyClass(int a, int b)
    {
        x = a;
        y = b;
    }

    MyClass(const MyClass &obj)
    {
        x = obj.x;
        y = obj.y;
    }

    void display()
    {
        cout << "x = " << x << ", y = " << y << endl;
    }
};

int main()
{
    MyClass obj1(10, 20);
    MyClass obj2 = obj1; // Copy constructor called

    obj1.display(); // Output: x = 10, y = 20
    obj2.display(); // Output: x = 10, y = 20

    return 0;
}
