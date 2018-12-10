class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        
        for (int i=1; i<=size; ++i)
        {
            int num = nums[i-1];
            while (num!=i && num<size && num>0 && num!=nums[num-1])
            {
                nums[i-1] = nums[num-1];
                nums[num-1] = num;
                num = nums[i-1];
            }
        }
        
        for (int i=1; i<=size; ++i)
        {
            if (nums[i-1] != i)
                return i;
        }
        
        return size + 1;
    }
};
