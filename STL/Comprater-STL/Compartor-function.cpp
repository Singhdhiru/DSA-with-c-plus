
// * what is Comparator ->> it is function or an object that is used to compare object;

/*? How to Create a Comparator in C++?
In C++, we can create a comparator function using four methods. They are:
Using Function Pointer
Using Functors -> function object
Using Lambda Expression
*/

// !1. Comparator Using Function Pointer
// In this method, we define a function that implements the comparison logic and returns some value. Then we use the pointer to this function as the comparator.

//* C++ program to create comparator using function pointer
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Custom comparison function
bool customComparison(int a, int b)
{
	// Custom comparison logic
	return a < b; // it sorts in ascending order

	// another wise -> upper mai ak line mai ho gaya hi
	if (a > b)
	{
		return false;
	}
	else
	{
		return true;
	}
}

// int main()
// {
// 	vector<int> myVec = { 7, 5, 2, 1, 4, 3 };

// Using sort with a function pointer
// 	sort(myVec.begin(), myVec.end(), customComparison);

// 	cout << "Sorted Vector: ";
// 	for (int num : myVec) {
// 		cout << num << " ";
// 	}
// 	cout << endl;

// 	return 0;
// }

// ! Write compartor to sort vector<pair<int, int>> in asecnding order
//* C++ program to create comparator using function pointer
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Custom comparison function
bool comparator(pair<int, int> &a, pair<int, int> &b)
{
	// * write comprator to sort element in desending order
	if (a.first > b.first){
		return true;
	}
	// ! dono ka first element same ho toh second ke hisab se sort kar do n
	if(a.first  == b.first){
		if(a.second > b.second){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false; 
	}
}
void print(vector<pair<int, int>> vec)
{
	for (pair<int, int> &it : vec)
	{
		cout << "{" << it.first << " " << it.second << "}"<< " ";
	}
}
int main()
{
	vector<pair<int, int>> vec = {{2, 3}, {1, 5}, {0, 7}, { 7,9}, {2,24}, {4,16}};
	sort(begin(vec), end(vec)); //! ye bas first element ko campare kr ke sort kr de raha hi agr first equal huaa toh second compare karega
	print(vec);
	cout<<endl;
	// ! per mai chahta hu comparator likh kr isk property change kr du
	// * mai comparator likha hu ki sort kare in desending order mai
	sort(begin(vec), end(vec), comparator);
	print(vec);
	return 0;
}
