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
    
    bool advanceK(ListNode* pnstart, ListNode** ppnend, int k) {        
       *ppnend = pnstart;
        for (int i=0; i<k; i++)
        {
            if (!*ppnend) return false;
            *ppnend = (*ppnend)->next;
        }
        
        return true;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return NULL;
        if (k <= 1) return head;
        
        ListNode **ppnstart = &head;
        ListNode *pnprev, *pncur, *pnfirst, *pnend, *pntmp;
        
        // For each k group in list
        while (*ppnstart)
        {
            pnprev = pnfirst = *ppnstart;
            bool ret = advanceK(pnfirst, &pnend, k);
            if (!ret) break;
            
            pncur = pnprev->next;
            
            // Set new end pointer for this k group
            pnprev->next = pnend;
            
            // Reverse each node in k group
            while (pncur && pncur!=pnend)
            {
                pntmp = pncur->next;
                pncur->next = pnprev;
                pnprev = pncur;
                pncur = pntmp;
            }
            
            // Set new start pointer preceding this k group
            *ppnstart = pnprev;
            
            ppnstart = &(pnfirst->next);
        }
        
        return head;
    }
};
