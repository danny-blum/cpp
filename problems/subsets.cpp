class Solution {
public:
    void findSubs(int start, vector<int>& nums, vector<vector<int>> &powset) {
        if (start == nums.size()) {
            vector<int> subs;
            powset.push_back(subs);
            return;
        }
        
        findSubs(start+1, nums, powset);
        int size = powset.size();
        for (int i=0; i<size; ++i) {
            vector<int> subs;
            subs.push_back(nums[start]);
            subs.insert(subs.end(), powset[i].begin(), powset[i].end());
            powset.push_back(subs);
        }
        
        return;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powset;
        findSubs(0, nums, powset);
        return powset;
    }
};
