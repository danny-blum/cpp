/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *pl1 = head;
        ListNode *tmp;
        ListNode *plh = pl1->next;
        ListNode *prev = NULL;
        
        while (pl1->next->next)
        {
            tmp = pl1->next;
            pl1->next = pl1->next->next;
            tmp->next = pl1;
            if (prev) prev->next = tmp;
            prev = pl1;
            pl1 = pl1->next;
            if (!pl1->next) break;
        }
        if (pl1->next)
        {
            if (prev) prev->next = pl1->next;
            pl1->next->next = pl1;
            pl1->next = NULL;
        }
        
        return plh;
    }
};
