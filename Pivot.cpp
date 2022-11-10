// find the pivot element in sorted and roteted array
// arr[] = { 1,23,44,56,78}; sorted array
// array roteted by two elememt 
// arr[] = image.png; roteted and sorted array
// output= 1;
 #include<iostream>
 using namespace std;
 int pivotelement(int arr[], int n ){
    int s = 0;
    int e = n-1;
    int mid= s+(e-s)/2;
    while(s<e){
        if(arr[mid] >= arr[0]){
            s = mid+1;
        }
        else{
            e= mid;
        }
        mid= s+(e-s)/2;
    }
    return s;
 }
 int main(){
    int arr[5] = { 78,96,100,1,2};
    cout<<"pivot element is equal to ="<<pivotelement(arr,5)<<endl;
    return 0;

 }