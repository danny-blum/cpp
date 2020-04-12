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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> vv;
        if (!root) return vv;
        
        pathSumSub(root, vv, sum, 0);
        
        return vv;
    }
private:
    void pathSumSub(TreeNode* node, vector<vector<int>> &vv, int rem, int level) {
        rem -= node->val;
        
        if (!node->left && !node->right) {
            if (0 == rem) {
                vector<int> v(level+1, 0);
                v[level] = node->val;
                vv.push_back(v); 
            }
            return;
        }
        
        int prevPaths = vv.size();
        if (node->left) {
            pathSumSub(node->left, vv, rem, level+1);
            for (int i=vv.size()-1; i>=prevPaths; --i)
                vv[i][level] = node->val;
            prevPaths = vv.size();
        }
        
        if (node->right) {
            pathSumSub(node->right, vv, rem, level+1);
            for (int i=vv.size()-1; i>=prevPaths; --i)
                vv[i][level] = node->val;
        }         
    }
};
