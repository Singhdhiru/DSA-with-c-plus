// reverse of vector
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> ReverseArray(vector<int>& v){
    int s = 0 ;
    int e = v.size()-1;
    while(s <= e){
        swap(v[s],v[e]);
        s++;
        e--;
    }
    return v;
}
void PrintArray(vector<int> ans){
    int n = ans.size();
    for(int i =0 ; i < n ; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> v;
    v.push_back(11);
    v.push_back(7);
    v.push_back(4);
    v.push_back(3);
    v.push_back(12);
    cout<<"print the array before reverse"<<endl;
    for(int i : v){
        cout<<i<<" ";
    }
    cout<<endl;
    vector<int> ans = ReverseArray(v);
    cout<<"print the vector after reverse"<<endl;
    PrintArray(ans);
}