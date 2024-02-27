#include <iostream>
#include <vector>
using namespace std;

/*
    MY YOUTUBE VIDEO ON THIS QN : https://www.youtube.com/watch?v=mrUBUWb23hk
    Company Tags    		: Amazon, Intuit, Microsoft, Flipkart
    Qn Link      		: https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1#
*/
// * ak aur method to check vector mai element is zero or not
// bool allZero(vector<int>counter){
//         for(auto &it : counter){
//             if(it != 0){
//                 return false;
//             }
//         }
//         return true;
//     }
bool allZero(vector<int>& count) {
    return count == vector<int>(26, 0);
}
int search(string pat, string txt) {
    int k = pat.size();
    // ? Freq Array
    vector<int> count(26, 0);
    for(char &ch : pat) {
        count[ch - 'a']++;
    }
    // ? apply Sliding Window
    int i = 0, j = 0;
    int n = txt.size();
    int result = 0;
    while(j < n) {
        // ? j = 0 pahle baar mai hoga use count mai use -- kro
        int idx = txt[j] - 'a';
        count[idx]--;

        // * agar window ka size pat ke size ke wqual ho tob
        if(j - i + 1 == k) {
            // ? all elements are zero
            if(allZero(count)) {
                result++;
            }
            // * zero n ho toh i ko badhane se oahle count mai add kr do
            count[txt[i] - 'a']++;
            i++;
        }
        
        // j to ++ hote rahega
        j++;
    }
    return result;
}

int main() {
    // Example usage
    string pattern = "abc";
    string text = "ababcababcabc";
    int occurrences = search(pattern, text);

    cout << "Number of occurrences: " << occurrences << endl;

    return 0;
}
