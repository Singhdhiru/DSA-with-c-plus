// Problem 3: Given an integer array ‘a’ sorted in non-decreasing order,
//  return an array of the squares of each
// number sorted in non-decreasing/increasing order.
// Input :[-10,-3,2,5,6]
// Output :[4,9,25,36,100]
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void SortSquaredArray(vector<int> & v){
    vector<int> ans;
    int left = 0 ;
    int right = v.size()-1;
    while(left<=right){ // agar "==" nahi lagayenge toh ak element skip ho jayegaa
        if(abs(v[left])<abs(v[right])){
            ans.push_back(v[right]*v[right]);
            right--;
        }
        else{
            ans.push_back(v[left]*v[left]);
            left++;
        }
    }
     reverse(ans.begin(), ans.end());
    for(int i = 0 ; i < ans.size() ; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int  n ;
    cout<<"enter the size of vector"<<endl;
    cin>>n;
    vector<int> v;
    cout<<"enter the element of vector"<<endl;
    for(int i = 0 ; i < n ; i++){
        int ele ;
        cin>>ele;
        v.push_back(ele);
    }
    SortSquaredArray(v);
}