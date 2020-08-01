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
    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;
        
        std::vector<int> vnums;
        std::vector<int>::iterator vnumsit;
        int sum = 0;
        
        sumNumbersSub(root, vnums, 0);
        
        for (vnumsit = vnums.begin(); vnumsit!=vnums.end(); ++vnumsit)
        {
            sum += *vnumsit;
        }
        
        return sum;
    }
private:
    
    void sumNumbersSub(TreeNode* cur, std::vector<int> &vnums, int curnum) {
        curnum *= 10;
        curnum += cur->val;
        
        if (!cur->left && !cur->right)
        {
            vnums.push_back(curnum);
        }
        else
        {
            if (cur->left)
                sumNumbersSub(cur->left, vnums, curnum);
            if (cur->right)
                sumNumbersSub(cur->right, vnums, curnum);
        }
    }
};
