// find the unique number in the array
// i/p = { 1 1  2 2 3 4 5}
// o/p = 5
// this method appaly only postive element present in a array
// time complexity = O(n^2)
#include<iostream>
using namespace std;
int main(){
    int arr[7] = {1,2,2,3,3,5,5};
    for(int i = 0 ; i < 7 ; i++){
        for(int j = i+1 ; j < 7 ; j++){
            if(arr[i] == arr[j]){
                arr[i] = arr[j] =-1;
            }
        }
    }
    for(int i = 0 ; i < 7 ; i++){
        if(arr[i]>0){
            cout<<arr[i]<<endl;
        }
    }
    
}
