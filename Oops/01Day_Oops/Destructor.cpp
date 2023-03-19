#include <iostream>
using namespace std;
class Hero
{
    private:
    int health;

    public:
    char *name;
    char level;
    //*Destructor
    ~Hero() {   
        cout << "Destructor bhai called" << endl;
    }
};
int main()
{
    //*Static
    Hero a; //*->>automatically called

    // *Dynamic
     Hero *b = new Hero();
    // *manually destructor call
    delete b;
}