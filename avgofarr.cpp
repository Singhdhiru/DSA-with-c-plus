// find average of arr
// sum of all array element 
//input array[5]={1,2,3,3,5}
//o/p =14
#include<iostream>
using namespace std;
int sumofarr(int arr[],int n){
      int sum=0;
      //addition of array
      for(int i=0;i<n;i++){
        sum=sum+arr[i];
      }
      return sum/n;
      }
int main(){
    int size;
    cout<<"enter size of array"<<endl;
    cin>>size;
    int arr[10];
    //printing a array
    for(int i=0;i<size;i++){
        cin>>arr[i];

    }
    cout<<"sum of alll array element is ="<<sumofarr(arr,size)<<endl;

}