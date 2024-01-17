#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {

        //? ṃethod ->> 1
        // t.c->O(n)
        // s.c->O(n)
        // unordered_map<int, int>mp;
        // for(int i=0; i<arr.size(); i++){
        //     mp[arr[i]]++;
        // }
        // set store only uniqu value
        // unordered_set<int>st;
        // for(auto &it : mp){
        //     int freq = it.second;
        //     if(st.find(freq) != st.end()){
        //         return false;
        //     }
        //     st.insert(freq);
        // }
        // return true;
        // ? method->2
        // ? constant space
        vector<int>freq(2001,0); //? s.c->>O(2001);
        for(int i=0; i<arr.size(); i++){
            freq[arr[i]+1000]++;
        }
        // ? sort function take time->>O(2001)
        sort(freq.begin(), freq.end());
        for(int i=1; i<2001; i++){
            if(freq[i]!=0 && freq[i]==freq[i-1]){
                return false;
            }
        }
        return true;
    }
int main() {
    vector<int> arr = {-2, -9, -9, -2, -2, 4 , 5, 5, 5, 5};
    bool ans = uniqueOccurrences(arr);
    cout<<"unique occ are present->> "<<ans;
    return 0;
}