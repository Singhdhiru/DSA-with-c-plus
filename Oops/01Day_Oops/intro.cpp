// * deatil of class and object
#include <iostream>
using namespace std;

class Person
{
public:
    // * data member
    string name;
    int age;

    void display() //* member function
    {
        cout << "Name: " << name << ", Age: " << age <<endl;
    }
};

int main()
{
    // * creating object-->>static allocation
    Person person1;
    person1.name = "Alice";  //* dot operator use to access data member
    person1.age = 25;
    person1.display();

    // * creating object-->>static allocation
    Person person2;
    person2.name = "Bob";
    person2.age = 30;
    person2.display();

    return 0;
}