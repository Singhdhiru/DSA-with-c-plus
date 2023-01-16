//  pair sum in array
#include<iostream>
using namespace std;
int getPairsCount(int arr[], int n, int k) {
        int count = 0 ;
        // bruteforce apporoch
        for(int i = 0 ; i < n-1 ; i++){
            int num = arr[i];
            for(int j = i+1 ; j < n ; j++ ){
                if(arr[j] == k - num){
                    count++;
                }
                
            }
        }
        return count;
         // optimize solution means two poienter apporoch-> if array is sorted
        // int cout = 0 ;
        // int i = 0 , j = n-1 ;
        //  sort(arr.begin(),arr.end());
        // while(i<j){
        //     if(arr[i] + arr[j] == k){
        //         cout++;
        //     }
        //     else if(arr[i] + arr[j] > k{
        //         j--;
        //     }
        //     else{
        //         i++
        //     }
        // } 
        // return cout;
}
int main(){
    int k;
    int arr[6] = {1,56,34,553,432,321};
    int ans = getPairsCount(arr,6,58);
    cout<<"total pairs sum count in array->"<<ans;
    return 0;
}