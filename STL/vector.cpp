//  vector -> 
// Vectors in STL are basically dynamic arrays that 
// have the ability to change size whenever elements
//  are added or deleted from them. Vector elements can 
//  be easily accessed and traversed using iterators. A vector
//   stores elements in contiguous
//  memory locations.
//Syntax:vector<object_type> variable_name;
#include<iostream>
#include<vector>
using namespace std;
int main(){
    // vector<int> a(5,1); // another way yo intialization of vector
    // 5 = size of vector, 1 = all element intilize with 1;
    // capacity  = kitna element daal sakte hi vector mai
    // size = kitna element hi vector
    // for(int i : a){
    //     cout<<i<<" ";
    // }
    // cout<<endl; 
    vector<int> v; // intialization of vector in STL
    cout<<"capacity->" << v.capacity()<<endl;
    v.push_back(1);  // push the element in vector
    cout<<"capacity->" << v.capacity()<<endl;
    v.push_back(2);
    cout<<"capacity->" << v.capacity()<<endl;
    v.push_back(3);
    cout<<"capacity->" << v.capacity()<<endl;
    cout<<"size of vector->"<<v.size()<<endl;
    cout<<"element at 2nd index->"<<v.at(2)<<endl;
    cout<<"first element of array"<<v.front()<<endl;
    cout<<"last element of array"<<v.back()<<endl;
     //pop_back()-> it deletes the last element and returns it to the calling function
    cout<<"element before pop"<<endl; 
    // print the array before the pop
    for(int i : v){
        cout<<i <<" ";
    }
    cout<<endl;
    v.pop_back();
    cout<<"element after the pop"<<endl;
    // print the vector after pop
    for(int i : v){
        cout<<i<<" ";
    }
    cout<<endl;
    // clear() – deletes all the elements from the vector.
    cout<<"before clear size"<<v.size()<<endl;
    v.clear();
    cout<<"after the clear size->"<<v.size()<<endl;
}