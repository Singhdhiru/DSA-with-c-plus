#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//!3016. Minimum Number of Pushes to Type Word II (3014 number bhi isis code se solve ho jayega usme her char ki freq 1 hogi)
    // ? jab word distinct n ho tab
int minimumPushes(string word)
{
    vector<int> freq(26, 0);
    for (int i = 0; i < word.size(); i++)
    {
        freq[word[i] - 'a']++;
    }
    // ? freq ko sort karne se ye hogga ki jo jayada baar aaya hi use pahle hi place per rakh du jayada press n karna pade->> 3016. Minimum Number of Pushes to Type Word II
    sort(freq.begin(), freq.end(), greater<int>()); // decending order mai sort hoga
    int result = 0;
    for (int i = 0; i < 26; i++)
    {
        int totalFreqOfWord = freq[i];
        //? ye karne se press count malum chalega
        int number_of_Press = i / 8 + 1; // ? maan lo word mai 8 se jayada char hi uska press count nikalne ke lie i =9, 9/8+1 = 2 matlb 2 se 8 tak akk ak char add kr liya hu phir se number 2 key per 9 char add hoga jise press karne mai 2 push lagega
        result += totalFreqOfWord * number_of_Press;
    }
    return result;
}
int main()
{
    // Example usage of the minimumPushes function
    string inputWord = "exxxxxample"; // Replace with your input word
    int result = minimumPushes(inputWord);

    // Display the result
    cout << "Minimum pushes required: " << result << endl;

    return 0;
}