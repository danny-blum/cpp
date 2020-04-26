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
    void flatten(TreeNode* root) {
        if (!root) return;
        
        flattenSub(root);
    }
private:
    TreeNode* flattenSub(TreeNode* node) {
        if (!node->left && !node->right)
            return node;
        
        TreeNode* left_end = NULL;
        TreeNode* right_start = node->right;
        TreeNode* right_end = NULL;
        if (node->left) {
            left_end = flattenSub(node->left);
            node->right = node->left;
            node->left = NULL;
        }
        
        if (right_start)
            right_end = flattenSub(right_start);
        
        if (left_end)
            left_end->right = right_start;
        
        if (right_end)
            return right_end;
        else
            return left_end;
        
    }
};
