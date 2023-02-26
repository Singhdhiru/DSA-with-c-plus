#include<iostream>
using namespace std;

void reachHome(int src, int dest){

    cout<<"source->"<<src<<" "<<"destnetion->"<<dest<<endl;
    if(src == dest){ //* base case
        cout<<"ghar pahuch gaya"<<endl;
        return;
    }
    //* processing ->> ek step aage badh jaoo
    src++;
    reachHome(src, dest);

}
int main(){
    int src = 1;
    int dest = 10;
    reachHome(src, dest);
    return 0;
}
