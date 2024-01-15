#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// ? leet Question->> 415. Add Strings
string add(string num1, string num2)
{
    int idx1 = num1.size() - 1;
    int idx2 = num2.size() - 1;
    int sum = 0;
    int carry = 0;
    string ans;
    while (idx2 >= 0)
    {
        sum = (num1[idx1] - '0') + (num2[idx2] - '0') + carry; // -'0 karne se int mai convert ho jayega
        // carry nikal ho
        carry = sum / 10;
        // agar sum> 10 then we want to push only 0 in ans string
        // zero kaise mile
        char c = '0' + sum % 10; // phie se char mai change krane ke liye '0' add kr dunga
        ans += c;
        idx1--;
        idx2--;
    }
    // only num1 bachega tab usko handle kr lunga
    while (idx1 >= 0)
    {
        sum = (num1[idx1] - '0') + carry; // -'0 karne se int mai convert ho jayega
        // carry nikal ho
        carry = sum / 10;
        // agar sum> 10 then we want to push only 0 in ans string
        // zero kaise mile
        char c = '0' + sum % 10; // phie se char mai change krane ke liye '0' add kr dunga
        ans += c;
        idx1--;
    }
    // base caes
    if (carry)
    {
        // jab idx1> idx2 se
        // aur num1 = 996780 num2 = 7890 last mai 1 carry bach hi jayega
        ans += '1'; // caryy one ho sakta hi
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
string addStrings(string num1, string num2)
{
    // num2 big hoga num1 hoga toh use change kr denge num2 ko num1
    if (num1.size() < num2.size())
    {
        return add(num2, num1);
    }
    else
    {
        return add(num1, num2);
    }
}
int main()
{
    string num1 = "000000";
    string num2 = "000";

    string result = addStrings(num1, num2);

    cout << "Sum: " << result << endl;
    return 0;
}
// output Sum: 000000

// if want to another output acording to gfg question
// if num1 = "000000" num2 = "00000"
// then output is->> only 0
// but above question give 0000000

/*
gfg Question->> https://www.geeksforgeeks.org/problems/sum-of-numbers-or-number1219/1
string add(string num1, string num2){
    int idx1 = num1.size()-1;
    int idx2 = num2.size()-1;
    int sum = 0;
    int carry = 0;
    string ans;
    while(idx2>=0){
        sum = (num1[idx1]-'0')+(num2[idx2]-'0')+carry; // -'0 karne se int mai convert ho jayega
        carry nikal ho
        carry = sum/10;
        agar sum> 10 then we want to push only 0 in ans string
        zero kaise mile
        char c = '0'+sum%10; // phie se char mai change krane ke liye '0' add kr dunga
        ans += c;
        idx1--;
        idx2--;
    }
    only num1 bachega tab usko handle kr lunga
    while(idx1>=0){
        sum = (num1[idx1]-'0')+carry; // -'0 karne se int mai convert ho jayega
        carry nikal ho
        carry = sum/10;
        agar sum> 10 then we want to push only 0 in ans string
        zero kaise mile
        char c = '0'+sum%10; // phie se char mai change krane ke liye '0' add kr dunga
        ans += c;
        idx1--;
    }
    base caes
    if(carry){
        jab idx1> idx2 se
        aur num1 = 996780 num2 = 7890 last mai 1 carry bach hi jayega
        ans += '1'; // caryy one ho sakta hi
    }
    ?this only add different from leet code  
    int i=ans.size()-1;
    while(i>0 && ans[i]=='0'){
        ans.pop_back();
        i--;
    }

    reverse(ans.begin(),ans.end());
    return ans;
}
*/