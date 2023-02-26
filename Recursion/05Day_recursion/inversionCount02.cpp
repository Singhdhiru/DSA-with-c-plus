// * inversion count using brute force method
#include<iostream>
using namespace std;

int inversionCount(int arr[], int n){
    int inverCnt = 0 ;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                inverCnt++;
            }
        }
    }
    return inverCnt;
}
int main(){
    int arr[] = {5, 3, 2, 1, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = inversionCount(arr, n);
    cout << "The total inversions are " << ans << endl;
    return 0;
}