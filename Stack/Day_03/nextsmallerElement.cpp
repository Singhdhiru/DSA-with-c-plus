#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> nextsmallerElement(vector<int> &v){
    int n = v.size();

    stack<int> s;
    s.push(-1);
    vector<int>ans(n);

    // ? last element ka koiee nextsmaller nahi hoga always -1;
    for(int i=n-1; i>= 0; i--){
        int curr = v[i];
        while(!s.empty() && s.top() >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

void print(vector<int>&v){
    vector<int>:: iterator it;
    for(it = v.begin(); it<v.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);;
    print(v);
    vector<int> final_ans = nextsmallerElement(v);
    print(final_ans);
    cout<<endl;
    return 0;
}