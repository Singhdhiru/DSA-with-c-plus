#include <iostream>
using namespace std;

string  moveXToEnd(string str, int idx, string newStr, int count){
    // base case
    if(idx == str.size()){
        for(int i=0; i<count; i++){
            newStr += 'x';
        }
        return newStr ;
    }
    char curr = str[idx];
    if(curr == 'x'){
        count ++;  
    }
    else{
        newStr += curr;
    }
    return moveXToEnd(str, idx+1, newStr, count);
}
int main() {
    string str = "axbbcdxrx";
    int count = 0;
    string ans = moveXToEnd(str, 0, "", count);
    cout<<"print ans-> "<<ans<<endl;
    return 0;
}
