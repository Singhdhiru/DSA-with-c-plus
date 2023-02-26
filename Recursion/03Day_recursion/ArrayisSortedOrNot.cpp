//* check array is sorted or not using recursion
#include<iostream>
using namespace std;

bool isSorted(int arr[] , int size){
    //* base case
    if(size==0 || size==1){
        return true ;
    }

    //* processing
    if(arr[0]>arr[1]){
        return false;
    }
    else{
        bool ans = isSorted(arr+1, size-1);
        return ans;
    }
}
int main(){
    int arr[6] = {2, 9, 10 ,12, 14, 45 };
    int size = 6;
    bool Ans = isSorted(arr,size);
    if(Ans){
        cout<<"arrey is sorted"<<endl;
    }
    else{
        cout<<"array is not sorted"<<endl;
    }
    return 0;
}