// Input :[1,2,3,4,5]
// Output :[4,2,3,1,5]
// move the all even element in the right side of array and odd element in the right side
//of the array  
/// note->order does not matter
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void SortByParity(vector<int>& v){
    int left = 0 ;
    int right = v.size()-1;
    while(left<=right){
        if(v[left]%2==1 && v[right]%2==0){
            swap(v[left],v[right]);
            left++;
            right--;
        }
        if(v[left]%2==0){
           left++;
        }
        if(v[right]%2==1){
            right--;
        }
    }  
    for(int i = 0 ; i < v.size() ;i++){
        cout<<v[i]<<" ";
    } 
    cout<<endl; 
  
}

int main(){
    int n ;
    cout<<"enter the lenght of vector"<<endl;
    cin>>n;
    vector<int> v;
    cout<<"enter the element of vector"<<endl;
    for(int i = 0 ; i < n ; i++){
        int ele ;
        cin>>ele;
        v.push_back(ele);
    }
    SortByParity(v);
}
