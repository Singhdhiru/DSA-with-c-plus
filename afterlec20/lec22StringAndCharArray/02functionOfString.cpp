#include <iostream>
#include <string>
using namespace std;
int main()
{
    // append function -> Extends the string by appending additional characters at the end of its current value:
    // simply add two string method->1
    string s1 = "fam";
    string s2 = "ily";
    string s3 = "rani";
    // s1.append(s2);
    // s1.append(s2.begin(),s2.end());
    s1 = s1 + s2;
    cout<<"print the s1->"<<s1<<endl;
    // append some specfic index in string 
    s3.append(s2.begin()+1, s2.end());
    cout<<"print the s1->"<<s3<<endl;
    
    // clear()->Erases the contents of the string, which becomes an empty string (with a length of 0 characters).
    string s4 = "sq1dnxswhnx shihnoshio ";
    s4.clear();
    cout<<"str4->"<<s4<<endl;

    // compare()->Compares the value of the string object (or a substring) to the sequence of characters specified by its arguments.- > comprision between two string
    string s5 = "abc";
    string s6 = "xyzdkdmsw";
    cout<<s6.compare(s5)<<endl;


    // empty()->Returns whether the string is empty (i.e. whether its length is 0).
    if(s5.empty()){
        cout<<"s5 is empty strin"<<endl;
    }else{
        cout<<"s5 is not empty"<<endl;
    }


    // erase()->Erases part of the string, reducing its length:
    s6.erase(s6.begin()+2, s6.end()-2);
    cout<<"print the s5 after the erasing->"<<s6<<endl;



}
