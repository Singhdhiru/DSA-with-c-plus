#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// ?3014. Minimum Number of Pushes to Type Word I

// ? ye apporach first->> jab distinct charcter ho word mai
int minimumPushes_onlyFor3014(string word) {
        int result = 0;
        int assign_key = 2;
        // key ->> 2 3 4 5 6 7 8 9
        unordered_map<int,int>mp;
        for( char &ch:word){
            // 9 se bahar ho ga toh phie 2 se sign suru hoga
            if(assign_key>9){
                assign_key = 2;
            }
            // ? map mai key ke samne assign karega paress count 
            mp[assign_key]++;
            result += mp[assign_key];
            assign_key ++;

        }
        return result;
    }

    // ? jab word distinct n ho tab
int minimumPushes_both3014_3016(string word)
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
    string inputWord = "example"; // Replace with your input word
    int result = minimumPushes_onlyFor3014(inputWord);

    // Display the result
    cout << "Minimum pushes required: " << result << endl;

    return 0;
}