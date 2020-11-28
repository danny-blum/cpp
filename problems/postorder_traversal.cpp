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
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> v;
        if (!root)
            return v;
        
        postorderTraversalIter(root, v);
        
        return v;
    }
    
    
private:
    void postorderTraversalIter(TreeNode* root, vector<int> &v) {
        std::stack<TreeNode*> s;
        std::stack<int> s_print;        
        TreeNode *cur = root;
        s.push(cur);        
        
        while (!s.empty())
        {
            cur = s.top();
            s.pop();
            
            if (cur->left)
                s.push(cur->left);
            if (cur->right)
                s.push(cur->right);
            
            s_print.push(cur->val);
        }
        
        while (!s_print.empty())
        {
            v.push_back(s_print.top());
            s_print.pop();
        }
    }
};
