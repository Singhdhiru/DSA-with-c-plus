// find the maixium and minimum element in the array
#include<iostream>
using namespace std;
int getmin(int arr[],int n){
    int min=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]<min){
            min = arr[i];
        }
        //rturing min value
        
    }
    return min;
}
int getmax(int arr[],int n){
    int max= arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];

        }
        // return max value
      
    }
      return max;

    
}
int main(){
    int size;
    cout<<"enter size of array"<<endl;
    cin>>size;
    int arr[100];
    //taking input in array
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"maixum value"<<getmax(arr,size)<<endl;
    cout<<"minimum value is ="<<getmin(arr,size)<<endl;  
}