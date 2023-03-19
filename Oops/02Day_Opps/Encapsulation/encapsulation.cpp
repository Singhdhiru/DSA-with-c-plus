#include<iostream>
using namespace std;

class Student {
    // * private member
    private:
        string name;
        int age;
        int height;

    // * get method use for access private data member
    public:
    int getage() {
        return this->age;
    }
    void setage(int newAge){
        age = newAge;
    }
};

int main() {

    Student first;
    first.setage(25);
    cout<<"print the age of student->"<<first.getage()<<endl;
    cout << "Sab sahi chalra hai" << endl;
    return 0;
}