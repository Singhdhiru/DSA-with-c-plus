#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    // creation
    unordered_map<string, int> mp;

    // insertion
    // method: 01
    pair<string, int> p = make_pair("babbar", 2);
    mp.insert(p);

    // method: 02
    pair<string, int> pair2("love", 3);
    mp.insert(pair2);

    // method: 03
    mp["mera"] = 1;


    // iterator
    unordered_map<string, int>::iterator it;

    // You can use the iterator 'it' to traverse the unordered_map
    for (it = mp.begin(); it != mp.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }


    // search
    cout << mp["mera"] << endl;
    cout << mp.at("love") << endl;

    // ! important concepts
    // ?search ->>> confusion 

    cout << mp["unknowKey"] << endl; // iska kaam hi aggar string present nahi hoga toh uska entry kar dega with key value is 0
    cout << mp.at("unknowKey") << endl; // at function entry nahi kar pata hi only search karta hi

    // ?search ->>> confusion 

    // cout << mp.at("apple") << endl;
    // cout << mp["apple"] << endl;
    
    // size
    cout<<"size of map:"<<mp.size()<<endl;

    // chek persence
    cout<<"chek the value is present or not:"<<mp.count("love")<<endl;
    
    // erase
    mp.erase("love");
    cout<<"size of map after erase:"<<mp.size()<<endl;

    return 0;
}
