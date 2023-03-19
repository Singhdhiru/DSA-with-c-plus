#include <iostream>
#include <cstring>
using namespace std;

class Hero {
private:
    int health;
public:
    char *name;
    char level;
    // *create static data member
    static int timeToComplete;
    // Parameterized constructor
    Hero(int health) {
        this->health = health;
        name = new char[100];
    }

    Hero(int health, char level) {
        this->health = health;
        this->level = level;
        name = new char[100];
    }

    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    void setHealth(int h) {
        health = h;
    }

    void setLevel(char ch) {
        level = ch;
    }

    //* create static function
    static int random() {
        return timeToComplete;
    }

};

//* initialize static data member outside the class
int Hero::timeToComplete = 44;

int main() {

    // *access static member using class name
    cout << Hero::timeToComplete << endl;

    // !creating object to access static member is not recommended
    // Hero a;
    // cout << a.timeToComplete << endl;

    //* access static function using class name
    cout << Hero::random() << endl;


    //! creating objects to access static member is not recommended
    // Hero b;
    // b.timeToComplete = 10;
    // cout << a.timeToComplete << endl;
    // cout << b.timeToComplete << endl;

    return 0;
}
