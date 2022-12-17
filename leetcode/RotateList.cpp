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
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *ptr1 = head;
        int len = 0;
        while (ptr1 != NULL)
        {
            ptr1 = ptr1->next;
            len++;
        }
        k = k % len;
        ptr1 = head;
        ListNode *ptr2 = head;
        if (k == 0)
        {
            return head;
        }
        else
        {
            while (k > 0)
            {
                ptr2 = ptr2->next;
                k--;
            }
            while (ptr2->next)
            {
                ptr2 = ptr2->next;
                ptr1 = ptr1->next;
            }
            ListNode *result = ptr1->next;
            ptr1->next = NULL;
            ptr2->next = head;
            return result;
        }
    }
};