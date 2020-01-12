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
    vector<TreeNode*> generateTrees(int n) {
        return generateSubTrees(1, n);
    }
private:
    vector<TreeNode*> generateSubTrees(int start, int end) {

        vector<TreeNode*> vt;        
        if (start > end) return vt;
        if (start == end) {
            vt.push_back(new TreeNode(start));
            return vt;
        }
               
        for (int i=start; i<=end; ++i) {
            vector<TreeNode*> vtl = generateSubTrees(start, i-1);
            vector<TreeNode*> vtr = generateSubTrees(i+1, end);
            int vtlSize = vtl.size();
            if (!vtlSize) vtlSize = 1;
            int vtrSize = vtr.size();
            if (!vtrSize) vtrSize = 1;

            for (int l=0; l<vtlSize; ++l) {
                for (int r=0; r<vtrSize; ++r) {
                    TreeNode *cur = new TreeNode(i);
                    if (vtl.size())
                        cur->left = vtl[l];
                    if (vtr.size())
                        cur->right = vtr[r];
                    vt.push_back(cur);
                }
            }
        }
        
        return vt;   
    }
};
