// Count Positive - Negative Pairs
#include<iostream>
using namespace std;
int  countPositiveNegativePairs(int arr[], int n)
{
    int totalpair = 0 ;
    for(int i = 0 ; i < n - 1 ; i++){
        for(int j = i+1 ; j < n - 1 ; j++){
            if(arr[i] = - arr[j]){
            //    if (arr[i] <= 0)
            //         {
            //            arr[i]=-arr[i];
            //         }
                totalpair ++;
            }
        }
    }
    return totalpair;
}
int main(){
    int n ;
    cout<<"enter the size of array"<<endl;
    cin>>n;
    int arr[] = {-1, 3, 6, 2, 5, -4, 3, 2, -4};
    // // input array element
    // for(int i = 0 ; i < n ; i++){
    //     cin>>arr[i];
    // } 
    // cout<<endl;
    int postivenegtivePair = countPositiveNegativePairs(arr,9);
    cout<<"print total postive negtive pair->"<<postivenegtivePair<<endl;
    return 0;
}