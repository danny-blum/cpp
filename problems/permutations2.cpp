class Solution {
public:
    
    vector<vector<int>> pstep(vector<int>& nums, vector<bool> used, int rem)
    {
        vector<vector<int>> vvret;
        int prev;
        bool prev_active = false;
        
        for (int i=0; i<nums.size(); ++i)
        {
            if (!used[i] && (!prev_active || prev!=nums[i]))
            {
                if (rem == 1)
                {
                    vvret.push_back(vector<int>(1,nums[i]));
                    return vvret;
                }
                else
                {
                    prev_active = true;
                    prev = nums[i];
                    vector<bool> used_cur = used;
                    used_cur[i] = true;
                    vector<vector<int>> vvcur;
                    vvcur = pstep(nums, used_cur, rem-1);
                    for (int j=0; j<vvcur.size(); ++j)
                    {
                        vector<int> v(1, nums[i]);
                        v.insert(v.end(), vvcur[j].begin(), vvcur[j].end());
                        vvret.push_back(v);
                    }
                }
            }
        }
        
        return vvret;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        return pstep(nums, vector<bool>(nums.size()), nums.size());
    }
};
