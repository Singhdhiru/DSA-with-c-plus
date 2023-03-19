// * read carefully
#include<iostream>
using namespace std;

class Hero
{
    public:
    int health;
    char level;
    Hero(){ //* constructor created-->>default
        cout<<"constructor called"<<endl;
    }
    // * parameterized constructor
    Hero(int health){
        cout<<"print the health->>"<<health<<endl;
    }
    // *  parameterized constructor
    Hero(int health, char level) {
        this -> level = level;
        this -> health = health;
        cout<<"print health->>"<<this->health<<endl;
        cout<<"print the level->>"<<this->level<<endl;
    }
    int gethealth(){
        return health;
    }
    char getlevel(){
        return level;
    }
    void sethealth(int new_health){
        health = new_health;
    }
    void setlevel(char new_level){
        level = new_level;
    }

};
int main(){
    // * creating object->>statically created
    Hero Dhiraj; //* automatically called constructor by compiler

    // * create object
    Hero ramesh(10); //* pass value in parameterizes constructor

    //  * create object
    Hero manis(20,'c');
    return 0;
}