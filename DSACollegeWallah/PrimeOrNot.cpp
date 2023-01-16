// Prime number is a number that is greater than 1 and divided by 1 or itself. In other words, prime numbers can't be divided by other numbers than itself or 1. For example 2, 3, 5, 7, 11, 13, 17, 19, 23.... are the prime numbers.
#include<iostream>
using namespace std;
bool isPrime(int n){
    // corner case
    if(n<=1){
        return false;
    }
    for(int i = 2 ; i < n ; i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int n ;
    isPrime(11) ? cout << " true\n" : cout << " false\n";
    isPrime(13) ? cout << " true\n" : cout << " false\n";
    return 0;
}