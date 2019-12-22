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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head) return head;
        if (m==n) return head;
        ListNode **ppstart = &head;
        ListNode **ppend = ppstart;
        ListNode *p1 = head;
        ListNode *p2 = p1;
        int i;
        
        for (i=2; i<=m; ++i) {
            if (!p1->next) return head;
            ppstart = &(p1->next);
            ppend = ppstart;
            p1 = p1->next;
        }
        
        p2 = p1;
        if (!p2->next) return head; 
        ppend = &(p2->next);
        p2 = p2->next;
        
        ListNode *p2_next;
        while (p2 && i<=n) {
            p2_next = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p2_next;
            i++;
        }
        
        *ppstart = p1;
        *ppend = p2;
        
        return head;
    }
};
