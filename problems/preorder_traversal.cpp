/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        
        if (root)
        {
            //preorderTraversalSub(root, v);
            preorderTraversalIterative(root, v);
        }
        
        return v;
    }
private:
    void preorderTraversalSub(TreeNode* node, vector<int> &v) {
        v.push_back(node->val);
        
        if (node->left)
            preorderTraversalSub(node->left, v);
        
        if (node->right)
            preorderTraversalSub(node->right, v);
    }
    
    void preorderTraversalIterative(TreeNode* node, vector<int> &v) {
        std::stack<TreeNode*> s;
        
        TreeNode* cur = node;
        s.push(cur);
        
        while(!s.empty())
        {
            cur = s.top();
            s.pop();
            
            v.push_back(cur->val);
            
            if (cur->right)
                s.push(cur->right);
            
            if (cur->left)
                s.push(cur->left);
        }
    }
};
