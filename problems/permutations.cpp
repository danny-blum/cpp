class Solution {
public:
    vector<vector<int>> pstep(vector<int>& nums, vector<bool> &used, int rem)
    {
        vector<vector<int>> vvret;
        if (nums.size() == 0)
            vvret.push_back(vector<int>());
        
        for (int i=0; i<nums.size(); ++i)
        {
            if (!used[i])
            {
                if (rem == 1)
                {
                    vvret.push_back(vector<int>(1, nums[i]));
                    return vvret;
                }
                
                vector<vector<int>> vvcur;
                vector<bool> used_cur = used;
                used_cur[i] = 1;
                vvcur = pstep(nums, used_cur, rem-1);
                for (int j=0; j<vvcur.size(); ++j)
                {
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.insert(v.end(), vvcur[j].begin(), vvcur[j].end());
                    vvret.push_back(v);
                }
            }
        }
        
        return vvret;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size());
        return pstep(nums, used, nums.size());
    }
};
