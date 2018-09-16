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
        ListNode *pl2 = head->next;
        ListNode *plh = NULL;
        ListNode **ppl = &plh;
        
        while (pl1 && pl2)
        {
            pl1->next = pl2->next;
            pl2->next = pl1;
            *ppl = pl2;
            ppl = &(pl1->next);
            pl1 = pl1->next;
            if (pl1)
                pl2 = pl1->next;
            else
                pl2 = NULL;
        }
        
        return plh;
    }
};
