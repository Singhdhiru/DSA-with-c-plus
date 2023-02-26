#include <iostream>
#include <string>
using namespace std;
int main()
{
    // intialize of string method->
    // string str ;
    // cout<<"enter the string->";
    // cin >> str ;
    // cout<<str<<endl;
    // method->2
    // intialize string which size is 5 and all element is same
    string str1(5, 'n');
    cout << "print the str1->" << str1 << endl;
    // method->3    cin-> ye space ke baad execution band kar deta hi
    string str2 = "dhirajsingh";
    cout << "print he str2->" << str2 << endl;
    // introduce new function-> getline(cin,name of string)
    string str3;
    cout << "enter the str3 element->";
    getline(cin, str3);
    cout << "print the str3->" << str3 << endl;
}
