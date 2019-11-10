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
    ListNode* partition(ListNode* head, int x) {
        ListNode** ppinsert = &head;
        ListNode* pcur = head;
        ListNode* pprev = NULL;
        ListNode* pnext;
        bool foundPivot = false;
        
        while(pcur) {
            pnext = pcur->next;
            if (foundPivot && pcur->val < x) {
                ppinsert = insert(ppinsert, pcur);
                pprev->next = pnext;
            }
            else if (!foundPivot && pcur->val >= x) {
                if (pprev)
                    ppinsert = &(pprev->next);
                foundPivot = true;
                pprev = pcur;
            }
            else {
                pprev = pcur;
            }
            pcur = pnext;
        }
        
        return head;
    }
    
private:
    
   ListNode** insert(ListNode** ppinsert, ListNode* pn) {
       ListNode* pnext = *ppinsert;
       *ppinsert = pn;
       pn->next = pnext;
       ppinsert = &(pn->next);
       
       return ppinsert;
   } 
};
