#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;
    heap(){
        size = 0;
        arr[0] = -1;
    }
    void insert(int val){
        size = size+1;
        int index = size;
        arr[index] = val;
        while(index>1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i=1; i<=size; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

    void deleteFromHeap(){
        if(size == 0){
            cout<<"no element found in heap"<<endl;
            return ;
        }
        // step->>> 01 put last element to root node
        arr[1] = arr[size];
        // step ->> 02 remove last element  
        size--;
        // step ->>03  take root node to ist correct position
        int i = 1;
        while(i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;
            if(leftIndex<size && arr[i]<arr[leftIndex]){
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex<size && arr[i]<arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return;
            }
        }
    }
};
int main(){
    heap h;
    h.insert(34);
    h.insert(50);
    h.insert(45);
    h.insert(67);
    h.insert(56);
    h.print();
    cout<<"delete root node from heap: ";
    h.deleteFromHeap();
    h.print();
}