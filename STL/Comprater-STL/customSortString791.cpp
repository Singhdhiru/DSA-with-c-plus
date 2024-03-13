#include<bits/stdc++.h>
using namespace std;
/*
	MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=oGPfmp71Zm4
    	Company Tags  		    : Facebook, Amazon
    	Leetcode Link 		    : https://leetcode.com/problems/custom-sort-string/
*/

/*
	*INTUITION : 
	The question is actually testing if we know about comparators in sorting.
	It just wants us to sort the string "str" but the ordering of characters must be in order
	of their indices they occur in string "order"
	
	It's similar to what I have shown below example :
	Example : 
	order = "cba"
	str      = "abcd"
	
	Assign numbers to characters of "order"
	c -> 0
	b -> 1
	a  -> 2
	
	Now, put those numbers in characters in "str"
	We get,
	a   b   c    d
	2   1   0   INF   (If a char is not present in "order" assign it the largest value)
	
	Now , we are sorting {2, 1, 0, INF} in ascending order
	{0, 1, 2, INF}
	correspnding characters are :
	{c, b, a, d}
	
	This is just the intuition about the approach.
	The actualy solution is just imply applying the comparator and it will be done.
*/
//*Approach-1 (Just making use of frequency of each char) : 
//*T.C : O(str.length())
//*S.C : O(26) ~ O(1)
string customSortString(string order, string str) {
        int count[26] = {0};
        
        for(char &x : str)
            count[x-'a']++;
        
        string result = "";
        for(char &ch : order) {
            while(count[ch-'a']--) {
                result.push_back(ch);
            }
        }
        
        //*Add the characters which are not present in 'order'
        for(char &ch : str) {
            if(count[ch-'a'] > 0) {
                result.push_back(ch);
            }
        }
        
        return result;
    }
//*Approach-2 (Using comparator)
//*T.C : O(nlogn)
//*S.C : O(26) ~ O(1)
    string customSortString_usingComparator(string order, string str) {
        vector<int> index(26, -1);
        
        for(int i = 0; i<order.length(); i++)
            index[order[i]-'a'] = i;
        
        
        auto lambda = [&index](char &ch1, char &ch2) {
            return index[ch1-'a'] < index[ch2-'a'];
        };
        
        sort(begin(str), end(str), lambda);
        return str;
        
    }

int main() {
    string str = "abcdef";
    string order = "cba";
    cout<<"sort the string in coustom order->> "<<customSortString(order, str)<<endl;
    return 0;
}