// A queue is a linear list of elements in which deletions can take place only at
// one end called the front, and insertions can take place only at the end called
// the rear. The queue is a First In First Out type of data structure (FIFO), the 
// terms FRONT and REAR are used in describing a linear list only when it is implemented as a queue.
// Syntax:
// queue<object_type> variable_name; 
#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<string> q;
    q.push("dhiraj");
    q.push("kumar");
    q.push("singh");
    cout<<"The size of the queue: "<<q.size()<<endl;
    cout<<"first element->"<<q.front()<<endl;
    q.pop();
    cout<<"first element after the pop->"<<q.front()<<endl;
    cout<<"size of queue after the pop->"<<q.size()<<endl;
}
