#include<iostream>
using namespace std;
bool findfeasible(int arr[] ,int n ,int k ,int mid){
    int painter = 1;
    int boardssum = 0;
    for(int i = 0 ; i < n ; i++){
        if(boardssum+arr[i]<=mid){
            boardssum = boardssum + arr[i];
        }
        else{
            painter ++ ;
            if(painter>k || arr[i]>mid){
                return false;
            }
            boardssum = arr[i];
        }
    }
    return true;
}
int painterpart(int arr[] ,int n , int k ){
     int sum = 0 ;
     int s = 0;
     for(int i = 0 ; i< n ; i++){
        sum = sum + arr[i];
     }
     int e = sum ;
     int mid = s + (e - s)/2;
     int ans = -1;
     while(s<= e){
       if(findfeasible(arr,n, k ,mid)){
         ans = mid;
         e = mid -1; // ans is possible then go to left part of a rray
       }
       else{
        s = mid + 1;
       }
       mid = s + (e - s)/2;
     }
     return mid ;
}
int main(){
    int arr[4] = {10,20,30,40};
    int n = 4;
    int k = 2;
    cout<<"minimum time to requried paint the board"<<" :"<<painterpart(arr,n,k)<<endl;
    return 0;
}