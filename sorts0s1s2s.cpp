// sort the given array or sorts the array in 0s ,1s,2s
// other name is DNF sorts
//i/p {1,1,2,0,0, 1,2}, o/p {0,0,1,1,1,2,2}
#include<iostream>
using namespace std;
void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void DNFsorts(int arr[], int n){
     int low = 0;
     int mid = 0;
     int high = n-1;
     while(mid<=high){
        if(arr[mid]==0){
            swap(arr,low,mid);
            low++,mid++;
        }
        else if(arr[mid] == 1){
            mid ++;
        }
        else{
            swap(arr,mid,high);
            high--;
        }
     }
}
int main(){
    int arr[9] = {1,1,1,2,0,0, 1,2};
    DNFsorts(arr,9);
    for(int i=0;i<9;i++){
       cout<<arr[i]<<" ";
    }
    return 0;

}