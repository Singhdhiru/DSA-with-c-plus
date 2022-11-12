// find factorial of any postive number
#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    int fact=1;
    if(n<0){
        cout<<"not possible"<<endl;
    }
    else{
        for(int i=1;i<=n;i++)
        {
            fact=fact*i;
        }
        cout<<"factorial of "<<" "<<n<<" ="<<fact;
    }
}