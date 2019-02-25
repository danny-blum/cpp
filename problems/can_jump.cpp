class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max = 0;
        int reach = 0;
        int end = nums.size() - 1;
        
        for (int i=0; i<=end; ++i)
        {
            if (max >= end)
                return true;
            
            reach = i + nums[i];
            if (reach > max)
                max = reach;
            
            if (max <= i)
                return false;
        }
        
        return true;
    }
};
