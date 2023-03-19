#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    char *name;

public:
    int age;

    // Default constructor
    Person()
    {
        age = 0;
        name = nullptr;
    }

    // Parameterized constructor
    Person(const char *n, int a)
    {
        age = a;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    // Copy constructor (deep copy)
    Person(const Person &p)
    {
        age = p.age;
        name = new char[strlen(p.name) + 1];
        strcpy(name, p.name);
    }


    void setName(const char *n)
    {
        if (name != nullptr)
        {
            delete[] name;
        }
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    void print()
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main()
{
    Person p1("John", 25);
    p1.print();

    Person p2 = p1; // Call copy constructor
    p2.setName("Jane"); //* see carefully

    p1.print(); // Original object should not be modified
    p2.print();

    return 0;
}
