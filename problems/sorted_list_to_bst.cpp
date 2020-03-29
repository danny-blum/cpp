/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int size = 0;
        ListNode* pLnCur = head;
        while (pLnCur) {
            size++;
            pLnCur = pLnCur->next;
        }
        if (!size)
            return NULL;
        
        return sortedListToBSTSub(&head, 0, size-1);
    }

private:
    TreeNode* sortedListToBSTSub(ListNode** ppLnCur, int start, int end) {
        if (start > end)
            return NULL;
        
        TreeNode *pTnCur = new TreeNode(0);
        int mid = (end - start)/2 + start;
        
        pTnCur->left = sortedListToBSTSub(ppLnCur, start, mid-1);
        
        pTnCur->val = (*ppLnCur)->val;
        *ppLnCur = (*ppLnCur)->next;
        
        pTnCur->right = sortedListToBSTSub(ppLnCur, mid+1, end);
        
        return pTnCur;
    }
};
