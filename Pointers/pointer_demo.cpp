#include<iostream>
using namespace std;
int main(){
    int fristvalue = 5 ;
    int secondvalue = 10 ;
    char thirdvalue = 'z';
    int *p1, *p2 ;
    char *p3;
    
    p1 = &fristvalue; // p1= address of first value
    p2 = &secondvalue; // p2 = address of second value
    p3 = &thirdvalue;  // p3= address of thirs value

    *p1 = 10 ; // value pointed by p1 is 10
    *p2 = *p1 ; // value pinted by p2 = value pointed by p1
    
    *p1 = 20 ; // value pointed by p1 is 20 ;
    *p3 = 'd'; // value pointed by p3 is 'd'
    cout<<"firstvalue->>>"<< fristvalue<<endl;
    cout<<"secondvalue->>>"<< secondvalue<<endl;
    cout<<"thirdvalue->>>"<< thirdvalue<<endl;

}