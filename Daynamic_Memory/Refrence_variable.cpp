#include <iostream>
using namespace std;

// * yaha per a and ans local variable hi jo block ke baad khatam ho jayega
int &func(int a) //! bad practice
{
    int num = a;
    int &ans = num;
    return ans;
}
//! bad practice
int *fun(int n) //* iska bhi koiee matlab nahi hi ye bhi local variable hi
{
    int *ptr = &n;
    return ptr;
}

void update2(int &n) //* ye pass by refrence hi
{
    n++;
}

void update1(int n) //* isme address modify hoga na ki value
{
    n++;
}

int main()
{

    
    int i = 5;
    //*create a ref variable
    int& j = i;
    cout << i << endl;
    i++;
    cout << i << endl;
    j++;
    cout << i << endl;
    cout << j << endl;
    

    int n = 5;

    cout << "Before " << n << endl;
    //update2(n);
    cout << "After " << n << endl;

    cout<<"before n-->>"<<n<<endl;
    fun(n);
    cout<<"after n->>"<<n<<endl;

    return 0;
}