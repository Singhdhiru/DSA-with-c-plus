// implmentation of insertion sort
// time complexity 
// space complexity
// it is best sorting algorithm comperision of bubbale sort , and selection sort.
// why iusing insertion sort ?
// . adaptable 
// . stable
#include<iostream>
using namespace std;
void insertionsort(int arr[] , int n){
     for(int i = 1 ; i < n ; i++){ // we assume first element of array is already sorted
        int temp = arr[i] ;
         int j = i -1;
         while(j >= 0 && arr[j] > temp){
            arr[j+1] = arr[j]; 
            j--;
         }
         arr[j+1] = temp ;

     }
}   
 void printarray(int arr[] , int n ){
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i] <<"  ";
    }
    cout<<endl;

}    

int  main(){
     int n ;
     cout<<"enter the size of array"<<endl;
     cin>>n;
     // take input array from the user
    int arr[10];
    for(int i = 0; i < n ; i++){
        cin >>arr[i];
    }
    insertionsort(arr , n);
    cout<<"print the arrayy after sorting"<<endl;
    printarray(arr,n);
    return 0;

}