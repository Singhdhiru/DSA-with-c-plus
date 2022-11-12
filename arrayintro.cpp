// paly with arrays like access array and print the array 
#include<iostream>
using namespace std;
  void printarr(int a[],int size){
      cout<<"printing the array"<<endl;
      /*print the array
      for(int i=0;i<size;i++){
           cout<<a[i]<<endl;
      }
      //take input array
      for(int i=0;i<size;i++){
           cin>>a[4];
      }*/
      cout<<"number present in 1st index ="<<a[1]<<endl;
      cout<<"printing is done"<<endl;
  }
 int main(){
    int size;
    cin>>size;
    int a[10] = {1,2,3};
  // int a[10];
    printarr( a,size);
     cout<<"everything is fine"<<endl;

 }