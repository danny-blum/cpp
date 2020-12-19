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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *lret = NULL;
        
        while (head)
        {
            ListNode *node = head;
            head = head->next;
            
            lret = insert(lret, node);
        }
        
        return lret;
    }
private:
    ListNode* insert(ListNode* lret, ListNode* node) {
        // Sorted list is empty, add node
        if (!lret)
        {
            node->next = NULL;
            return node;
        }
        
        // node is less than head, make it the new head
        if (node->val <= lret->val)
        {
            node->next = lret;
            return node;
        }
            
        // Advance cur to where node should be inserted as next
        ListNode* cur = lret;
        while (cur->next && (node->val > cur->next->val))
            cur = cur->next;
                   
        // Insert after cur
        node->next = cur->next;
        cur->next = node;
        
        return lret;
    }
};
