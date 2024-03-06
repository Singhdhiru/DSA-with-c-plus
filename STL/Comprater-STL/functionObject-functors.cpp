/*
!2. Comparator Using Functor (Function Object) ->> calss ya struct bna kr kiya jata hi
A functor (Function Object) is a class or struct that overloads the operator() such that it behaves as a function when called. We can also use such objects as a comparator by defining the comparison logic inside the () operator overloading function.
*/
// C++ program to create comparator using functor 

#include <algorithm> 
#include <iostream> 
#include <vector> 
using namespace std; 

// defining Functor (Function Object) 
class Comparator { 
    public:
	bool operator()(int a, int b) const
	{ 
		// Custom comparison logic 
		return a < b; // this sorts in ascending order 
	} 
}; 

int main() 
{ 
	// Creating a vector of integers 
	vector<int> myVec = { 9, 2, 4, 1, 6, 3 }; 

	// Using sort() with a functor (function object) 
	sort(myVec.begin(), myVec.end(), Comparator()); 

	// Printing the sorted vector 
	cout << "Sorted Vector: "; 
	for (int i : myVec) { 
		cout << i << " "; 
	} 
	cout << endl; 

	return 0; 
}
