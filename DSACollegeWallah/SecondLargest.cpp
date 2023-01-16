// find the second largest element in a array
// i/p = {2,3,4,5,7,6}
// O/P = 6
#include<iostream>
using namespace std;
int SecondLargest(int arr[],int n){
    int max = INT64_MIN;
    int second_max = INT64_MIN;
    for(int i = 1 ; i < n ; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(arr[i]>second_max && arr[i]!=max){
            second_max = arr[i];
        }
    }
    return second_max;
}
int main(){
    int n ;
   // cout<<"enter the size of array"<<endl;
    int arr[6] = {1, 2, 4, 7, 7, 6};
    int secondMax = SecondLargest(arr,n);
    cout<<"print  the second maaximum number"<<secondMax<<endl;
}