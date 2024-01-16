#include<bits/stdc++.h>
using namespace std;

// ? leet code -> 380. Insert Delete GetRandom O(1)
class RandomizedSet
{
public:
    vector<int> nums;
    unordered_map<int, int> idxMap;

    RandomizedSet() {}

    bool insert(int val)
    {
        if (idxMap.find(val) != idxMap.end())
        {
            return false;
        }
        nums.push_back(val);
        idxMap[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (idxMap.find(val) == idxMap.end())
        {
            return false;
        }
        int last = nums.back();
        // ise idx nikal lunga value ka
        idxMap[last] = idxMap[val];
        // last element ko swap kr do val se taki ham delete kr paye O(1)mai
        nums[idxMap[last]] = last;
        nums.pop_back();
        idxMap.erase(val);
        return true;
    }

    int getRandom()
    {
        return nums[rand() % nums.size()];
    }
};
int main() {
    // Create an instance of the RandomizedSet class
    RandomizedSet randomizedSet;

    // Insert elements into the set
    randomizedSet.insert(1);
    randomizedSet.insert(2);
    randomizedSet.insert(3);

    // Remove an element from the set
    randomizedSet.remove(2);

    // Get a random element from the set
    int randomElement = randomizedSet.getRandom();

    // Display the results
    cout << "Random Element: " << randomElement << endl;

    return 0;
}
