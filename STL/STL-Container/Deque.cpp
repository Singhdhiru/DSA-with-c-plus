// Double Ended Queue which is also called Deque is a type
//  of queue data structure in which insertion and deletion of elements can be either
//  in front or rear.
// Syntax:deque<object_type> variable_name; 
#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int>d;
    d.push_back(1); // push the element in back side
    d.push_back(4);
    d.push_back(5);
    d.push_back(6);
    d.push_front(2); // push the element 
    // print the element of deque
    for(int i : d){
        cout<<i <<" ";
    }
    cout<<endl;
    // delete the element from front
    //pop_back() – deletes the last element of the deque.
    d.pop_front();
    for(int i : d){
        cout<<i <<" ";
    }
    cout<<endl;
    cout<<"print the first index of element ->"<<d.at(1)<<endl;
    //front() – it gives a reference to the first element of the deque.
    // back() – it gives a reference to the last element of the deque.
    cout<<"front"<<d.front()<<endl;
    cout<<"back"<<d.back()<<endl;
    // empty() – to check if the deque is empty or not.
    cout<<"check the deque is empty or not->"<<d.empty()<<endl;
    cout<<"size of deque before erase"<<d.size()<<endl;
    // erase() – to delete a single element or elements between a particular range.
    d.erase(d.begin(),d.begin()+1);
    cout<<"size of deque after erase"<<d.size()<<endl;
    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;
}