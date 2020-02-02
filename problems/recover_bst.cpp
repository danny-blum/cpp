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
    void recoverTree(TreeNode* root) {
        if (!root) return;
        
        RecoverState rs;
        rs.prev = NULL;
        rs.first = NULL;
        rs.second = NULL;
        
        recoverTreeSub(root, &rs);
        
        // swap first with second
        if (!rs.first || !rs.second) return;
        int tmp = rs.first->val;
        rs.first->val = rs.second->val;
        rs.second->val = tmp;
    }
private:
    struct RecoverState {
        TreeNode * prev;
        TreeNode * first;
        TreeNode * second;
    };
    
    void recoverTreeSub(TreeNode* node, RecoverState *rs) {
        if (!node || !rs)
            return;
            
        if (node->left)
            recoverTreeSub(node->left, rs);
        
        if (rs->prev && rs->prev->val > node->val) {
            if (!rs->first)
                rs->first = rs->prev;
                rs->second = node;
        }
        rs->prev = node;
            
        if (node->right)
            recoverTreeSub(node->right, rs);
        
        return;
    }
};
