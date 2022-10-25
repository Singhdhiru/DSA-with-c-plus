// scope of array 
#include<iostream>
using namespace std;
void array(int arr[],int n){
    cout<<"array inside function"<<endl;
    arr[1]=120;
    //print array 
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"succesful array print "<<endl;
    
}
int main(){
    int arr[5]={1,23,25,34,11};
    array(arr,5);
   for(int i=0;i<5;i++){
    cout<<arr[i]<<" ";
   }
    cout<<"array outside of function"<<endl;
}// agar ham user define function mai array ko update karenge 
// toh wo main  function mai bhi update ho jayegaa