class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int size = nums.size();
        if (size <= 0)
            return 0;
        int a = 0;
        int b = 0;
        int b_next = 0;
        
        for (int i=0; i<size; ++i)
        {
            b_next = (~nums[i] & b) | (nums[i] & (~a & ~b));
            a = (~nums[i] & a) | (nums[i] & (~a & b));
            b = b_next;
        }
        
        return b;
    }
};
