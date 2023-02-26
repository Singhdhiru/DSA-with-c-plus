// in this code find the lenght of string
#include<iostream>
using namespace std;
int getLenght(char string[]){
    int lenght = 0 ;
    for(int i = 0 ; string[i] != '\0' ; i++){
        lenght++;
    }
    return lenght;
}
int main(){
    char string[20];
    cout<<"enter the string"<<endl;
    cin>>string;
    cout<<"lenght of string"<<getLenght(string)<<endl;
    return 0;
}