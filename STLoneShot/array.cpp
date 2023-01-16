// array using STL
#include<iostream>
#include<array>
using namespace std;
int main(){
   // int array[6] = {2,3,4,5,56,6}; // intialization of basic array
    array<int,4> arr = {1,2,3,4}; // arrai intialization in STL
    int size = arr.size() ; // size of array in STL
    for(int i = 0 ; i < size ; i ++){
        cout<<arr[i] << endl;
    } 
    // random axcessing of element 
    cout<<"element present in 2nd index" << arr.at(2)<<endl;
    cout<<"element present in 3rd index" << arr.at(3)<<endl;
    // using empty function to check the array is empt or not
    cout<< "array empty or not"<<arr.empty() <<endl;
    // check first and last element of arary
    cout<<"first element of array"<<arr.front()<<endl;
    cout<<"last element of array"<<arr.back()<<endl;
}

