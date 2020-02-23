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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> vv;
        if (!root) return vv;
        std::deque<TreeNode *> dq;
        int lvl = 0;
        int curLvlCnt = 0;
        int nextLvlCnt = 0;
        TreeNode* cur;
        
        dq.push_back(root);
        curLvlCnt++;
        
        while (!dq.empty()) {
            if (lvl%2 == 0) {
                cur = dq.front();
                dq.pop_front();
                if (cur->left) {
                    dq.push_back(cur->left);
                    nextLvlCnt++;
                }
                if (cur->right) {
                    dq.push_back(cur->right);
                    nextLvlCnt++;
                }
            }
            else {
                cur = dq.back();
                dq.pop_back();
                if (cur->right) {
                    dq.push_front(cur->right);
                    nextLvlCnt++;
                }
                if (cur->left) {
                    dq.push_front(cur->left);
                    nextLvlCnt++;
                }
            }
            if (vv.size() <= lvl)
                vv.push_back(vector<int>());
            vv[lvl].push_back(cur->val);
            
            curLvlCnt--;
            if (!curLvlCnt) {
                lvl++;
                curLvlCnt = nextLvlCnt;
                nextLvlCnt = 0;
            }
        }
        
        return vv;
    }    
};
