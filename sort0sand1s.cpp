// sort the array in 0s and 1s
// arr[3] = { 1,1,0}
// o/p   = {0,1,1}
#include<iostream>
using namespace std;
void printarr(int arr[],int size){
    // print the array after sort 0s and 1s
    for(int i = 0 ;i < size ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void SortOne(int arr[],int size){
    int left =0 , right  = size-1;
    while(left<right){
        while(arr[left]== 0 && left<right){
            left ++;
        }
        while(arr[right] == 1 && left<right){
            right --;
        }if(left<right){
            swap(arr[left] , arr[right]);
            left++;
            right--;
        }
    }
}
int main(){
    int arr[6] = {1,0,1,1,0,1};
    SortOne(arr,5);
    printarr(arr,6);
    return 0;
}