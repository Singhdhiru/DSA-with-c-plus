/*
!3. Comparator Using Lambda Expression
Lambda expressions can be used to declare the inline function definitions. We can also use the lambda expression to create a comparator just like we can do with function. Moreover, we can declare the lambda expression in a place where the comparator is required.
*/
// C++ program to create comparator using Lambda function 
#include <algorithm> 
#include <iostream> 
#include <vector> 
using namespace std; 

int main() 
{ 
	// Creating a vector of integers 
	vector<int> myVec = { 4, 3, 8, 1, 7, 2 }; 

	//! Using sort() with a lambda function  ye thoda boring lag raha hi expression 
	// sort(myVec.begin(), myVec.end(), [](int a, int b) { 
		// Custom comparison logic 
	// 	return a < b; // this sorts in ascending order 
	// }); 

    // ! ise aur aache se likh sakta hu
    auto myLamda = [](int &a, int &b){ //* ssquare baracket ko capture cluse karte hi usme kuch bhi like -> [a,b],  ya [map] int main mai hu use lamda expression mai use kr sakte hi
        return a>b; //! desending order mai sort karega
    };
    sort(begin(myVec), end(myVec), myLamda);

	// printing sorted vector 
	cout << "Sorted Vector: "; 
	for (int i : myVec) { 
		cout << i << " "; 
	} 
	cout << endl; 
	return 0; 
}
