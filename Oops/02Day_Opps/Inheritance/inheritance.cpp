#include <iostream>
using namespace std;

// * super or base class
class Human
{

public:
    int height;
    int weight;
    int age;

public:
    int getAge()
    {
        return this->age;
    }

    void setWeight(int w)
    {
        this->weight = w;
    }
};

// *child or sub class->> we can also write additional data member and fuction in child class
class Male : public Human
{

public:
    string color;

    void sleep()
    {
        cout << "Male Sleeping" << endl;
    }

    int getHeight()
    {
        return this->height;
    }
};
int main()
{
    // * create the object
    Male object1;
    
    cout << object1.age << endl;
    cout << object1.weight << endl;
    cout << object1.height << endl;
    cout << object1.color << endl;

    object1.setWeight(84);
    cout << object1.weight << endl;
    object1.sleep();
}