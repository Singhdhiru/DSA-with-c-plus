//* compile time polymorphism->> achive by function overloading and operator overloading
#include<iostream>
using namespace std;

class A {
    public:
    // * Fuction overloading ->> same name but different arguments
    // * function overloading achive by three way->>
    // * 1. diffrent types of arguments
    // * 2. different number of arguments
    // * 3. Defalut arguments
    void sayHello() {
        cout << "Hello Love Babbar" << endl;
    }
    
    int sayHello(char name) {
        cout << "Hello Love Babbar!" << endl;
        return 1;
    }

    void sayHello(string name) {
        cout << "Hello " << name  << endl;
    }

};
int main(){
    A obj1;
    obj1.sayHello();
    obj1.sayHello('A');
    obj1.sayHello("Dhiraj");
    return 0;
}
// * codestudio ducmentation