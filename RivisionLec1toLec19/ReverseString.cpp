// in this code we see how to reverse string
#include<iostream>
using namespace std;
void reverseString(char name[], int n){
    int s = 0 ;
    int e = n-1 ;
    while(s<e){
        swap(name[s++] , name[e--]);
    }
}    
int getLenght(char name[]){
    int lenght = 0 ;
    for(int i = 0 ; name[i] != '\0' ; i++){
        lenght++;
    }
    return lenght;
}
int main(){
    char name[20];
    cout<<"enter the name"<<endl;
    cin>>name;
    cout<<"youe name is "<<name<<endl;
    int n = getLenght(name);
    cout<<"name lenght"<<n<<endl;
    reverseString(name,n);
    cout<<"reverse name is "<<name;
    return 0;
}