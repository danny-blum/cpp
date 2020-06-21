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
    int maxPathSum(TreeNode* root) {
        if (!root) return maxSum;
        
        int rootSum = maxPathSumSub(root);
        
        return std::max(rootSum, maxSum);
    }
    
private:
    int maxPathSumSub(TreeNode* cur) {
        int leftSum = 0;
        int rightSum = 0;
        int curRootSum;
        
        if (cur->left)
            leftSum = maxPathSumSub(cur->left);
        if (cur->right)
            rightSum = maxPathSumSub(cur->right);
        
        if (leftSum < 0)
            leftSum = 0;
        if (rightSum < 0)
            rightSum = 0;
        
        curRootSum = cur->val + leftSum + rightSum;       
        if (curRootSum > maxSum)
            maxSum = curRootSum;
        
        
        return (std::max(leftSum, rightSum) + cur->val);
    }
    
    int maxSum = INT_MIN;
};
