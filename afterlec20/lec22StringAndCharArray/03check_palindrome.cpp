// leet code and code studio Question
#include <bits/stdc++.h>
#include <cctype>
using namespace std ;
char tolower_case(char ch ){
        if(ch >= 'a' && ch <= 'z'){
            return ch ;
        }
        else{
            int temp = ch - 'A' + 'a' ;
            return temp ;
        }
}    
// char tolower_case(char ch ){
//         return tolower(ch);
// }
bool checkPalindrome(string s){
    s.erase(remove_if(s.begin(), s.end(), ::ispunct), s.end());
    // remove all whitespace
    s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
    int st = 0 ;
    int e = s.length() - 1;
    while(st <= e){
        if(tolower_case(s[st]) != tolower_case(s[e])){
            return false ;
        }
        else{
            st++;
            e--;
        }
    }
    return true ;
}
int main(){
    // string s = "A man, a plan, a canal: Panama";
    string s = "N2 i&nJA?a& jnI2n" ;
    cout<<"chek palindrome or not->"<<checkPalindrome(s)<<endl;
    return 0 ;
}