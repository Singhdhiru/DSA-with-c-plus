#include <iostream>
#include <cstring>
using namespace std;

class Hero {
private:
    int health;
public:
    char *name;
    char level;

    // Default constructor
    Hero() {
        cout << "Simple constructor called" << endl;
        name = new char[100];
    }

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

    //* Copy constructor
    // Hero(Hero &temp) {
    //     cout << "Copy constructor called" << endl;
    //     health = temp.health;
    //     level = temp.level;
    //     name = new char[strlen(temp.name) + 1];
    //     strcpy(name, temp.name);
    // }

    void print() {
        cout << endl;
        cout << "[ Name: " << name << " ,";
        cout << "health: " << health << " ,";
        cout << "level: " << level << " ]";
        cout << endl;
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

    void setName(char name[]) {
        strcpy(this->name, name);
    }
};

int main() {
    Hero hero1; // Call default constructor
    hero1.setHealth(100);
    hero1.setLevel('A');
    hero1.setName("Batman");
    hero1.print();

    Hero hero2(hero1); // Call copy constructor
    hero2.print();

    // * mai hero 1 mai change karunge wo hero2 mai reflect hoga use shallow copy kahte hi
    hero1.name[0] = 'D';
    hero1.print();
    hero2.print();

    return 0;
}
