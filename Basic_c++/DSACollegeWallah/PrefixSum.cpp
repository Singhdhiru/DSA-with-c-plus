// Problem 1: Given an integer array ‘a’, return the prefix sum/ running 
// sum in the same array without creating a
// new array
#include<iostream>
#include<vector>
using namespace std;
void runingsum(vector<int>& v){
    for(int i = 1 ; i < v.size() ;  i++){
        v[i] = v[i-1] + v[i];
    }
    return ;
}
int main(){
    int n ;
    cout<<"enter the size of array"<<endl;
    cin>>n;
    vector<int> v ;
    for(int i = 0 ; i  < n ; i++){
        int ele ;
        cin>>ele;
        v.push_back(ele);
    }
    cout<<endl;
    runingsum(v);
    for(int i = 0 ; i  < v.size() ; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

}