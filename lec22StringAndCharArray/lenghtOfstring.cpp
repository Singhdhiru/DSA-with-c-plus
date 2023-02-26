#include<iostream>
using namespace std;
int getLenght(char name[]){
    int lenght = 0 ;
    for(int i = 0 ; name[i] != 0 ; i++){
        lenght ++ ;
    }
    return lenght ;
}
int main(){
    char name[20] ;
    cout<<"enter the char->"<<endl;
    cin>>name;
    int Ans = getLenght(name);
    cout<<"lengh of string is ->"<<Ans <<endl;
    return 0;

}