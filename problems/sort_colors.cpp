class Solution {
public:
    void sortColors(vector<int>& nums) {
        int idx0 = 0;
        int idx2 = nums.size() - 1;
        int cur = 0;
        
        while (cur <= idx2)
        {
            if (nums[cur] == 0)
            {
                nums[cur] = nums[idx0];
                nums[idx0] = 0;
                idx0++;
                cur++;
            }
            else if (nums[cur] == 2)
            {
                nums[cur] = nums[idx2];
                nums[idx2] = 2;
                idx2--;        
            }
            else
                cur++;
        }
    }
};
