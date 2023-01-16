// in the file we are reverse the array 
#include<iostream>
using namespace std;
void ReverseArray(int arr[] , int size){
    int start = 0 ;
    int end = size-1;
    int temp ;
    while(start<=end){
        // swap(arr[start] , arr[end] );-> iske behiend the senn
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void PrintArray(int arr[],int size){
    for(int i = 0 ; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr1[6] = {1,23, 89,90,67,89 };
    int arr2[5] = {23,89,80,56,34};
    ReverseArray(arr1,6);
    ReverseArray(arr2,5);
    PrintArray(arr1,6);
    PrintArray(arr2,5);
    return 0;
    
}