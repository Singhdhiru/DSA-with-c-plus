#include<iostream>
using namespace std;

void print(int *p) {

    cout << *p << endl; 

}

void update(int *p) {

    p = p + 1; //* update address not value
    cout << "inside "<< p <<endl;
   *p = *p + 1; //* update the value

}

int getSum(int *arr, int n) {

    cout << endl << "Size : " << sizeof(arr) << endl; //* give the size of pointers and array->>o/p->>4 not 24

    int sum = 0;
    for(int i=0;i<n;i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int value = 5;
    int *p = &value;
    print(p);
    cout <<" Before " << *p << endl;
    update(p);
    cout <<" After " << *p << endl;
    

    int arr[6] = {1,2,3,4,5,8};

    cout << "Sum is " << getSum(arr+3 ,3) << endl ;  //* give the value from 3 index not 0th index

    return 0;
}