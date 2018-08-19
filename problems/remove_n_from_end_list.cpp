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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1 = head;
        ListNode **pp2 = &head;
        
        if (!head || n<1) return head;
        
        // Advance p1 by n-1
        while (n > 1)
        {
            p1 = p1->next;
            if (!p1) return head;
            n--;
        }
        
        // Advance both until p1 is at the end
        while (p1->next)
        {
            p1 = p1->next;
            pp2 = &((*pp2)->next);
        }
        
        // Remove nth from end
        *pp2 = (*pp2)->next;
        
        return head;
    }
};
