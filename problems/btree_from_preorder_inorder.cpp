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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size()==0 || inorder.size()==0)
            return NULL;
        
        TreeNode *root = new TreeNode(0);
        int i = 0;
        int j = 0;
        buildTreeSub(root, false, 0, i, j, preorder, inorder);
        
        return root;
    }
private:
    void buildTreeSub(TreeNode *cur,
                      bool jskipEn, int jskip,
                      int &i, int &j,
                      vector<int>& preorder, vector<int>& inorder) {
                
        // place preorder[i]
        cur->val = preorder[i];
        
        if (i == preorder.size()-1) {
            i++;
            return;
        }
        
        // left subtree
        if (inorder[j] != preorder[i]) {
            cur->left = new TreeNode(0);
            buildTreeSub(cur->left, true, cur->val, ++i, j, preorder, inorder);
        }
        else {
            i++;
            j++;
        }
        
        if (i >= preorder.size())
            return;
        
        // right subtree
        if (!jskipEn || inorder[j]!=jskip) {
            cur->right = new TreeNode(0);
            buildTreeSub(cur->right, jskipEn, jskip, i, j, preorder, inorder);
        }
        else
            j++;
            
        return;  
    }
};
