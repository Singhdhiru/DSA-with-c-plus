#include <iostream>
using namespace std;
bool isPossible(int arr[], int n , int k, int mid){
    int cowCount = 1;
    int cowPositinon = arr[0];
    for(int i = 0 ; i < n ; i++){
        if(arr[i] - cowPositinon >= mid){
            cowCount++;
            if(cowCount == k){
                return  true ;
            }
            cowPositinon = arr[i];
        }
    }
    return false;
}
int aggressiveCows(int arr[], int n, int k)
{
    int s = 0;
    int maximum = -1;
    for (int i = 0; i < n; i++)
    {
        maximum = max(maximum, arr[i]);
    }
    int e = maximum;
    int ans = -1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if(isPossible(arr, n ,k , mid)){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans ;
}
int main()
{
    int arr[] = {1, 2, 4, 8, 9};
    int k = 2;
    cout<<"minimum distence between cows ->"<<aggressiveCows(arr , 5 , 3)<<endl;
    return 0;
}