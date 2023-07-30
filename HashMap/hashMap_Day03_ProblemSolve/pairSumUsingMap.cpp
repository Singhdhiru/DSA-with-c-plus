#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> targetSumPair(vector<int>& v, int targetSum){
    unordered_map<int, int>m;
    vector<int>ans(2,-1);
    for(int i=0; i<v.size(); i++){
        if(m.find(targetSum - v[i]) != m.end()){
            ans[0] = m[targetSum- v[i]];
            ans[1] = i;
            return ans;
        }
        else{
            m[v[i]] = i;
        }
    }
    return ans;
}
int main() {
    vector<int> v = {1, 4, 5, 11, 13, 10, 2,9};
    vector<int>ans = targetSumPair(v, 23);
    for(auto i: ans){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}