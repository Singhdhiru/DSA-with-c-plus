// * deatil explanation of getter and setter->>>Getters and setters allow you to control how important variables are accessed and updated in your code

#include<iostream>
#include<string>
using namespace std;
// * by defalut class me private modifier laga hota hi
class Student{
    public:
    string name ;
    int age ;
    string score;
    void print(){
        cout<<"name os student->>"<<name<<endl;
    }
    // * use of getter
    
    // *Getter method to retrieve the value of age
    int getage(){
        return age;
    }
    
    // *Getter method to retrieve the value of score
    string getscore(){
        return score;
    }

    // * use of setter
    // *Setter method to update the value of age
    void setage(int new_age){
        age = new_age;
    }
    //* Setter method to update the value of score
    void setscore(string newScore){
        score = newScore;
    }
};

// * find the size of class->> only two variable the size is 5 bytes but give me 8 bytes why?????????
class Ramesh {
public:
    int age;
    char sex;
    
    Ramesh(int a, char s) {
        age = a;
        sex = s;
    }
};
int main(){

    // * creating object-->> static alllocation
    Student topper;
    topper.name = "ram";
    cout<<"name os student->>"<<topper.name<<endl;


    // * function member->>> access
    topper.print();


    // * print the age using setter function
    topper.setage(25);
    topper.setscore("A");
    cout<<"age->>"<<topper.getage()<<endl;
    cout<<"score->>"<<topper.getscore()<<endl;

    cout<<"size of class->>"<<sizeof(Ramesh)<<endl;
    return 0;
}
