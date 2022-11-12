// reverse the array
#include<iostream>
using namespace std;
void revers(int arr[],int n){
    int start=0;
    int end=n-1;
    while(start<=end){
            swap(arr[start],arr[end]);
            start++;
            end--;
    }
}
void printarr(int arr[],int n){
   for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
   }
   cout<<endl;
}
int main(){
    int arr[5] = {4,56,76,78,45};
    int brr[6] = {45,78,76,5,45,41};
    revers(arr,5);
    revers(brr,6);
    printarr(arr,5);
    printarr(brr,6);
 cout<<"everthing is fine bro"<<endl;
}