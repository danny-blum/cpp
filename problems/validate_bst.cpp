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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        return isValidBSTSub(root, INT_MIN, INT_MAX);
    }
private:
    bool isValidBSTSub(TreeNode* node, int min, int max) {        
        if (node->val<min || node->val>max)
            return false;
        
        if (node->left && node->val==INT_MIN)
            return false;
        if (node->right && node->val==INT_MAX)
            return false;
        
        if (node->left && !isValidBSTSub(node->left, min, node->val-1))
            return false;
        if (node->right && !isValidBSTSub(node->right, node->val+1, max))
            return false;
        
        return true;
    }
};
