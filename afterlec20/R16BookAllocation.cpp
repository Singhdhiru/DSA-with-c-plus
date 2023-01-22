#include<iostream>
using namespace std;
bool isPossible(int arr[],int n, int k, int mid ){
    int studentCount = 1 ;
    int pageSum = 0 ;
    for(int i = 0; i < n; i++){
        if(pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }
        else{
            studentCount ++;
            if(studentCount > k || arr[i] > mid){
                return false ;
            }
            pageSum = arr[i];
        }
    }
    return true ;
}
int minPages(int arr[] ,int n , int k){
    int s = 0 ;
    int sum = 0 ;
    for(int i = 0 ; i < n ; i++){
        sum += arr[i];
    }
    int e = sum ;
    int mid = s + (e - s)/2;
    int ans = 0 ;
    while(s<=e){
        if(isPossible(arr, n , k , mid)){
            ans = mid ;
            e = mid -1 ;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e - s)/2;
    }
    return ans ;
}
int main(){
    int arr[4] = {10, 20, 30, 40};
    int k = 2;
    int Ans =  minPages(arr, 4 , 2 );
    cout<<"minimum number of pages read by student ->"<<Ans<<endl;
    return 0;
}