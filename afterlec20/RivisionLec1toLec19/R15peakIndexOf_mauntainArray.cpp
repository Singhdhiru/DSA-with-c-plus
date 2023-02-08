#include<iostream>
#include<vector>
using namespace std;
int PeakindexIn_mountainArray(vector<int> v){
    int s = 0 ;
    int e = v.size()-1;
    int mid = s + (e - s)/2;
    while( s < e){
        if(v.at(mid) < v.at(mid+1)){
            s = mid + 1 ;
        }
        else{
            e = mid ;
        }
        mid = s + (e - s)/2;
    }
    return v.at(e) ;
}
int main(){
    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(1);
    int ans = PeakindexIn_mountainArray(v); 
    cout<<"peak indx in mountain array->"<<ans<<endl;
    return 0;
}