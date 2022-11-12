// addition of two array and store on third array
#include<iostream>
using namespace std;
int  thirdarr(int arr[],int brr[] ,int size){
    //addition of two array
    int crr[10];
    for(int i=0;i<size;i++){
       crr[i]=arr[i]+brr[i];
    }
    // printing the array
    cout<<"we foun addition of two array"<<endl;
    for(int i=0;i<size;i++){
        cout<<crr[i]<<" ";
    }
    cout<<endl;
    return crr[size];
}
int main(){
    int n;
    cout<<"enter the size of array"<<endl;
    cin>>n;
    int arr[10];
    cout<<"enter the first element of array"<<endl;
    //taking input of array
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl;
    //taking the second array as input
    int brr[10];
    cout<<"enter the second array element "<<endl;
    for(int i=0;i<n;i++){
        cin>>brr[i];
    }
    cout<<endl;
     thirdarr(arr,brr,n);
}