// Note: In C++ STL by default max-heap is created.
// In the case of the max heap-> its first element is always the greatest of the 
// elements it contains and the rest elements 
// are in decreasing order.
// in case of the min heap->s first element is always the smallest of the 
// elements it contains and the rest elements are in increasing order.
// The syntax for a max-heap priority queue->
// priority_queue<object_type> variable_name;
// The syntax for a min-heap priority queue->
// priority_queue<object_type,vector<object_type>,greater<object_type>> variable_name;
#include<iostream>
#include<queue>
using namespace std;
int main()
{
    // intailization of max heap
    priority_queue<int> maxi;
    // intialization of min heap
    priority_queue<int,vector<int>,greater<int>> mini ;
    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(0);
    cout<<"size->"<<maxi.size()<<endl;
    int n = maxi.size();
    for(int i = 0 ; i < n ; i++){
        cout<<maxi.top()<<" ";
        maxi.pop();
    }
    cout<<endl;
    mini.push(5);
    mini.push(1);
    mini.push(0);
    mini.push(4);
    mini.push(3);
    int m = mini.size();
    for(int i = 0 ; i < m ; i++){
        cout<<mini.top()<<" ";
        mini.pop();
    }
    cout<<endl;
    cout<<"khali hi kya bhai"<<mini.empty()<<endl;

}
