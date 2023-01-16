// find the min and max elementt in the array
#include<iostream>
#include<limits.h>
using namespace std;
int getMin(int arr[] , int size){
    int min = INT_MAX;
    for(int i = 0 ; i < size ; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    // returing minimun value of array
    return min;
}
int getMax(int arr[] , int size){
    int max = INT_MIN;
    for(int i = 0 ; i < size ; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    // returning maximum value in array
    return max;
}
int main(){
    int size;
    cout<<"Enter the size of array->"<<endl;
    cin>>size;
    int arr[100];
    // taking input in array
    for(int i = 0 ; i <= size ; i++){
        cin>>arr[i];
    }
    cout<<endl;
    cout<<"Maximum element in the array is->"<<getMax(arr,size)<<endl;
    cout<<"Minimum element in the array is->"<<getMin(arr,size)<<endl;
    return 0;
}
