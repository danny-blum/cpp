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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode** ppprev = &head;
        ListNode* pcur = head;
        ListNode* pstart = head;
        bool dup = false;
        
        while (pstart) {
            if (pcur == pstart) {
                pcur = pcur->next;
                dup = false;
            }
            else if (pcur && pcur->val == pstart->val) {
                dup = true;
                pcur = pcur->next;
            }
            else {
                if (dup) {
                    // remove duplicate nodes
                    *ppprev = pcur;
                }
                else {
                    // keep non-duplicate nodes
                    ppprev = &(pstart->next);
                }
                pstart = pcur;
            }    
        }
        
        return head;
    }
};
