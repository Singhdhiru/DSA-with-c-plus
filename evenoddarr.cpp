// check the total number of even odd element in array
#include<iostream>
using namespace std;
int checkarr(int arr[],int n){
    int count=0;
    for(int i=0;i<n;i++){
     if(arr[i]%2==0){
            count++;
        }    
    }
    return count;
}
int main(){
    cout<<"enter the total size of array"<<endl;
    int size;
    cin>>size;
    int arr[20];
    for(int i=0;i<size;i++){
       cin>>arr[i];
    }
    int ans=checkarr(arr,size);
    cout<<"answer is ="<<" "<<ans<<endl;
}