#include <iostream>
using namespace std;

string intToRoman(int num)
{
    string symbol[]={"M","CM","D","CD","C","XC","L","XL","X",
        "IX","V","IV","I"};

        int value[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};

        int i=0;
        string ans="";
        while(i<13){
            while(num>=value[i]){
                ans+=symbol[i];
                num=num-value[i];
            }
            i++;
        }
        return ans;
}
int main()
{
    int num = 579;
    string ans = intToRoman(num);
    cout<<"int to roman conversion of "<<num<<" is " <<ans<<endl;
    return 0;
}