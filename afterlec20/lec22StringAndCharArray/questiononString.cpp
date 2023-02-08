// form a biggest number from numeric string
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s = "96489784";
    sort(s.begin(),s.end(), greater<int>());
    cout<<"from biggest numeric string from number->"<<s<<endl;
    return 0;
}

