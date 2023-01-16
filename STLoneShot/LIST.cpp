// A list in STL is a contiguous container that allows
//  the inserting and erasing of elements in constant time and iterating in both directions.
// Syntax:
// list<object_type> variable_name; 
#include<iostream>
#include<list>
using namespace std;
int main(){
//list<int> n(5,100);
//for(int i : n){
//    cout<<i <<" ";
//}
//cout<<endl;
list<int> li; // intialization of list in stl;
li.push_back(1);
li.push_front(2);
for(int i : li){
    cout<<i<<" ";
}
cout<<endl;
//erase() – to delete a single element or elements between a particular range.
li.erase(li.begin());
cout<<"print the list after the erase"<<endl;
for(int i : li){
    cout<<i<<" ";
}
cout<<endl;
cout<<"size of list"<<li.size()<<endl;
}