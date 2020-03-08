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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (!inorder.size() || !postorder.size())
            return NULL;
        
        return buildTreeSub(inorder, postorder, 0, 0, inorder.size()); 
    }
private:
    TreeNode* buildTreeSub(vector<int>& inorder, vector<int>& postorder,
                           int i, int j, int size) {
        TreeNode* cur = new TreeNode(postorder[j+size-1]);
        
        int lsize = 0;
        while (inorder[i+lsize] != cur->val)
            lsize++;
        int rsize = size - lsize - 1;
        if (lsize)
            cur->left = buildTreeSub(inorder, postorder, i, j, lsize);
        if (rsize)
            cur->right = buildTreeSub(inorder, postorder, i+lsize+1, j+lsize, rsize);
        
        return cur;   
    }
};
