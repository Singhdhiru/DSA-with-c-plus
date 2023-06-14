#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Queue{
    Node* head = NULL;
    Node* tail = NULL;
    int size;
    public:
    Queue(){
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }
    void enqueue(int data){
        Node* newNode = new Node(data);
        if(this->head == NULL){
            // ? LL is empty
            this->head= this->tail = newNode;
        }
        else{
            this->tail->next = newNode;
            this->tail = newNode;
        }
        this->size++;
    }
    void dequeue(){
        if(this->head == NULL){
            // ? LL is empty now
            return;
        }
        else{
            Node* oldHead = this->head;
            Node* newHead = this->head->next;
            this->head = newHead;
            // ? only one nodeis available
            if(this->head == NULL){
                this->tail = NULL;
            }
            oldHead->next = NULL; //* oldHead ko Null Bnakr delete karenge
            delete oldHead;
        }
        this->size--;
    }
    int getSize(){
        return this->size;
    }
    int getFront(){
        if(this->head == NULL)
        return -1;

        return this->head->data;
    }
    bool isEmpty(){
        return this->head == NULL;
    }
    
};

int main(){
    Queue qu;
    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.dequeue();
    qu.enqueue(40);
    while(!qu.isEmpty()){
        cout<<qu.getFront()<<" ";
        qu.dequeue();
    }
    cout<<endl;

    // cout<<"first element is->>   "<<qu.getFront()<<endl;
    return 0;
}