// * gfg artical ->>https://www.geeksforgeeks.org/copy-constructor-in-cpp/
#include <iostream>
using namespace std;

class Hero
{
public:
    int health;
    char level;
    Hero()
    { //* constructor created-->>default
        cout << "constructor called" << endl;
    }
    // * parameterized constructor
    Hero(int health)
    {
        cout << "print the health->>" << health << endl;
    }
    // *  parameterized constructor
    Hero(int health, char level)
    {
        this->level = level;
        this->health = health;
        cout << "print health->>" << this->health << endl;
        cout << "print the level->>" << this->level << endl;
    }
    // * copy constructor -->> created
    Hero(Hero &temp)
    { //* address pass karna hota nahi toh infiinte loop mai fas jayega
        cout<<"called copy constructor"<<endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    int gethealth()
    {
        return health;
    }
    char getlevel()
    {
        return level;
    }
    void sethealth(int new_health)
    {
        health = new_health;
    }
    void setlevel(char new_level)
    {
        level = new_level;
    }
    void print(){
        cout<<"Health is->>"<<this->health<<endl;
        cout<<"Level is ->>"<<this->level<<endl;
    }
};
int main()
{
    // * creating object->>statically created
    // Hero Dhiraj; //* automatically called constructor by compiler

    // * create object
    // Hero ramesh(10); //* pass value in parameterizes constructor

    //  * create object
    // Hero manis(20,'c');

    Hero s(70, 'f'); //* s hero ko r mai taransfer karna ho toh copy constructor ka kaam padta hi
    s.print();
    Hero r(s);
    r.print();
    return 0;
}