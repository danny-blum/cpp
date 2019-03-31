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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;
        
        ListNode *pprev, *prot, *plast;
        int size = 1;
        int rot;
        
        plast = head;
        while (plast->next)
        {
            plast = plast->next;
            size++;
        }
        
        rot = k % size;
        if (rot > 0)
        {
            pprev = head;
            for (int i=0; i<size-rot-1; ++i)
                pprev = pprev->next;
            
            prot = pprev->next;
            pprev->next = NULL;
            plast->next = head;
            head = prot;
        }
        
        return head;
    }
};
