// Stack in STL.
// A stack is a non-primitive linear data structure. it
// is an ordered list in which the addition of a new data item and deletion of the already
// existing data item is done from only one end known as the top of the stack (TOS). The element 
// which is added in last will be first to be removed and the element which is inserted first 
// will be removed in last. As all the deletion and insertion in a stack are done from the 
// top of the stack, the last added element will be the first to be removed from the stack. 
// That is the reason why stack is also called Last-in-First-out (LIFO).
// Syntax:
// stack<object_type> variable_name;
#include<iostream>
#include<stack>
using namespace std;
int main()
{
   stack<string> s;
   //push() – to insert an element in the stack.
   s.push("dhiraj") ;
   s.push("kumar") ; 
   s.push("singh");
   //top() – returns the element at the top of the stack.
    cout<<"top element->"<<s.top()<<endl;
   // pop() – deletes the last element of the stack.
   s.pop();
   cout<<"top element->"<<s.top()<<endl;
   cout<<"size of stack->"<<s.size()<<endl;
   cout<<"empty or not->"<<s.empty()<<endl;
}