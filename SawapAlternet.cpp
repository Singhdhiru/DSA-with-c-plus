// swap alternet value of array
// i/p arr[5] = {12,34,24 35,67};
//o/p arr[5] = {34,12,35,24,67};
#include<iostream>
using namespace std;
void printarr(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void swapalternet(int arr[],int n){
     // traversing of array
     for(int i=0;i<n;i+=2){// yaha per i ko do baar increment krenge
        if(i+1<n){
            swap(arr[i],arr[i+1]);
        }
     }
}
int main(){
    int odd[5] = {12,34,56,67,75};
    int even[6] = {11,22,333,44,55,66};
     swapalternet(odd,5);
     printarr(odd,5); 
     swapalternet(even,6);
     printarr(even, 6);
}