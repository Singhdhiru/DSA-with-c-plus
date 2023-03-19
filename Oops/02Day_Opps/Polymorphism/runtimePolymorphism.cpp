#include<iostream>
using namespace std;

// * understand the method overloading
class Animal {
    public:
    void speak() {
        cout << "Speaking "<< endl;
    }
};

class Dog: public Animal {

    public:
    // * modify speak function own oue needs->>this is called method overloading
    void speak() {
        cout << "Barking " << endl;
    }


};

int main(){
    // * crate object;
    Dog obj1;
    obj1.speak();
}
