#include<iostream>
#include<stack>
#include<string>
using namespace std;

int findMinimumCost(string str){
    int n = str.length();
    if(n % 2 == 1){
        return -1;
    }

    stack<char> s;
    for(int i=0; i<n; i++){
        char ch = str[i];
        if(ch == '{'){
            s.push(ch);
        }

        else{
            // ? ch is closed brace
            if(!s.empty() && s.top() == '{'){
                s.pop();
            }
            else{
                s.push(ch);
            }
        }
    }

    // ? stack containd invalid expression 
    int a = 0, b = 0;
    while(!s.empty()){
        if(s.top() == '{'){
            b++;
        }
        else{
            a++;
        }
        s.pop();
    }

    int ans = (a+1)/2 + (b+1)/2;
    return ans;
}
int main(){
    string str = "{{{{";
    cout<<"minimum cost to make string is invalid->> "<<findMinimumCost(str)<<endl;
    return 0;
}