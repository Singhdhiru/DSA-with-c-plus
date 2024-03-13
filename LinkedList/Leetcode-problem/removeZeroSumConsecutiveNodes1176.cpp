#include<bits/stdc++.h>
using namespace std;
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=5UWEVMg10rY
    Company Tags                : NA
    Leetcode Link               : https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//*T.C : O(n^2)
//*S.C : O(n) - We took a map
ListNode *removeZeroSumSublists(ListNode *head)
{
    unordered_map<int, ListNode *> mp;
    ListNode *dummyNode = new ListNode(0);
    dummyNode->next = head;
    mp[0] = dummyNode;
    int prefixSum = 0;

    while (head != NULL)
    {
        prefixSum += head->val;
        if (mp.find(prefixSum) != mp.end())
        {
            // yani ab delet kro linkList se
            ListNode *P = mp[prefixSum];
            ListNode *start = P;
            int pSum = prefixSum;
            // head tak delete karte jana hi head jaha hi waha zero huaa toh head ko dala hi nahi
            while (start != head)
            {

                start = start->next;
                pSum += start->val;
                if (start != head)
                    mp.erase(pSum);
            }

            P->next = start->next;
        }
        else
        {
            mp[prefixSum] = head;
        }
        head = head->next;
    }
    return dummyNode->next;
}

int main()
{
    // Creating a sample linked list for testing
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(-3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(1);

    // Calling the function
    ListNode *result = removeZeroSumSublists(head);

    // Printing the result
    cout << "Resulting Linked List: ";
    while (result != nullptr)
    {
        cout << result->val << " ";
        result = result->next;
    }

    // Clean up: Delete the allocated memory
    while (head != nullptr)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
