// find the oocurrences of element in array
#include<iostream>
using namespace std;
int getOccurences(int arr[] , int size , int element){
    int count = 0 ;
    for(int i = 0 ; i < size ; i++){
        if(arr[i] == element){
            count++;
        }
    }
    return count;
}
int main(){
    // int size;
    // cout<<"enter the size array ->";
    // cin>>size;
    // int arr[100];
    // cout<<"enter the element in the array->"<<endl;
    // for(int i = 0  ; i < size ; i++){
    //     cin>>arr[i];
    // }
    int arr[6] = {1, 2, 3, 5,5, 5 };
    int Ans = getOccurences(arr,6 , 5);
    cout<<"Occurences of element is->"<<Ans<<endl;
    return 0;
}