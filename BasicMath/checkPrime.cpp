// time complexity->O(n-2) == O(n)
#include<iostream>
using namespace std;

bool check_prime(int n){

    if(n<=1){
        return false;
    }

    for(int i=2; i<n; i++){
        if(n%i==0){
            return false;
        }
    }
    return true;

}
int main(){
    int n;
    cout<<"enter the number for checking->";
    cin>>n;

    if(check_prime(n)){
        cout<<"number is prime"<<endl;
    }
    else{
        cout<<"number is not prime"<<endl;
    }
    return 0;
}