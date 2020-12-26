/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return head;
        
        int len = 0;
        ListNode* cur = head;
        
        // Determine list length
        while (cur)
        {
            len++;
            cur = cur->next;
        }
        
        head = mergeSortList(head, len);
        
        return head;
    }
private:
    ListNode* mergeSortList(ListNode* node, int len) {
        if (0 == len) return NULL;
        if (1 == len) return node;
        
        int m = len/2;
        ListNode* mid = node;
        ListNode* preMid = node;
        
        // Find mid point
        for (int i=0; i<m; ++i)
        {
            if (i == m-1)
                preMid = mid;
            mid = mid->next;
        }
        preMid->next = NULL;
        
        // Sort left half
        ListNode* left = mergeSortList(node, m);
        
        // Sort right half
        ListNode* right = mergeSortList(mid, len-m);
        
        // Merge lists
        ListNode* sorted = NULL;

        if (right->val < left->val)
        {
            sorted = right;
            right = right->next;
        }
        else
        {
            sorted = left;
            left = left->next;
        }

        ListNode* cur = sorted;
        for (int i=1; i<len; ++i)
        {
            if (!left)
            {
                cur->next = right;
                break;
            }
            else if (!right)
            {
                cur->next = left;
                break;
            }
            else
            {
                if (right->val < left->val)
                {
                    cur->next = right;
                    right = right->next;
                }
                else
                {
                    cur->next = left;
                    left = left->next;                    
                }
                cur = cur->next;
            }
        }
        
        return sorted;
    }
};
