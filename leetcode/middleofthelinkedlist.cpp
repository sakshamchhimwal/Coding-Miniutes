#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        vector<ListNode *> loc;
        int i = 0;
        while (head->next != NULL)
        {
            loc.insert(loc.begin() + i, head);
            head = head->next;
            i++;
        }
        if(loc.size()%2==0)
            return loc.at(loc.size()/2);
        else
            return loc.at((loc.size()/2)+1);
    }
};