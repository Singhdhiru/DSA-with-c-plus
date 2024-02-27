#include <bits/stdc++.h>
using namespace std;
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=hxEWwnJJKcY
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/find-all-people-with-secret/
*/
//*Approach-1 (Most basic approach that can come to mind)
// T.C : ~O(M*(M+N)) where M = number of meetings and N = number of people
// S.C : O(M+N)

typedef pair<int, int> p;
vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
{
    // map asecnding order mai store karega
    // map<time, vector<pair<person1, person2>> >
    map<int, vector<p>> timeMeeting;
    for (vector<int> &meet : meetings)
    {
        int person1 = meet[0];
        int person2 = meet[1];
        int time = meet[2];
        timeMeeting[time].push_back({person1, person2});
    }

    // we can make knowSecrate vector to populate the info who is know
    // secarte
    vector<bool> knowsecrate(n, false);
    knowsecrate[0] = true;
    knowsecrate[firstPerson] = true;

    for (auto &it : timeMeeting)
    {
        int t = it.first;           // this is time
        vector<p> meet = it.second; // meet main meeting store hoga jisme
                                    // mai do log honge

        // adj list ready karunga ab
        unordered_map<int, vector<int>>
            adjList; // int -> time hoga, vector<int> -> kinta meeting hoga
                     // yani kitna node hoga
        queue<int> q;
        unordered_set<int> visted; // ye avoid karegaa duplicate

        for (auto &twoPerson:meet)
        { 
            int person1 = twoPerson.first;
            int person2 = twoPerson.second;
            // bio-directinal hi
            adjList[person1].push_back(person2);
            adjList[person2].push_back(person1);

            // add into queue -> kab add karnge jab wo visted n ho and
            // knoesecrate false ho toh
            if (knowsecrate[person1] &&
                visted.find(person1) == visted.end())
            {
                q.push(person1);
                visted.insert(person1);
            }
            if (knowsecrate[person2] &&
                visted.find(person2) == visted.end())
            {
                q.push(person2);
                visted.insert(person2);
            }
            // Now I know who meet who based on increasing time
            // Let's hit the BFS to spread the secret
            while (!q.empty())
            {
                int person = q.front();
                q.pop();
                for (auto &nextPerson : adjList[person])
                {
                    if (knowsecrate[nextPerson] == false)
                    {
                        knowsecrate[nextPerson] = true;
                        q.push(nextPerson);
                    }
                }
            }
        }
    }
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        if (knowsecrate[i] == true)
        {
            res.push_back(i);
        }
    }
    return res;
}

int main()
{
    int n = 5;
    vector<vector<int>> meetings = {{0, 1, 5}, {1, 2, 10}, {0, 3, 15}, {3, 4, 20}};
    int firstPerson = 0;

    vector<int> result = findAllPeople(n, meetings, firstPerson);

    cout << "People who know the secret: ";
    for (int person : result)
    {
        cout << person << " ";
    }

    return 0;
}
