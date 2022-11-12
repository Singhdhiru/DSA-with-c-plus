// linear search of an array & find key element of array
#include<iostream>
using namespace std;
  bool search(int arr[],int n, int key){
      for(int i=0;i<n;i++){
        if(arr[i]==key){
            return 1;
        }
      }
      return 0;

     
  }
int main(){
    int arr[8] = {22,-56,54,98,100,34,1};
    cout<<"enter the key element for searching"<<endl;
    int key;
    cin>>key;
     bool found=search(arr,10,key);
    if(found){
        cout<<"the key element is present"<<endl;
    }
    else{
        cout<<"the key element is absent"<<endl;
    }

}