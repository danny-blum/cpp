class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) return;
        int max_prev = nums[size-1];
        int max_prev_idx = size-1;
        bool swapped = false;
        
        for (int i=size-2; i>=0; --i)
        {
            int cur = nums[i];
            if (cur < max_prev)
            {
                int min_greater = max_prev;
                int min_greater_idx = max_prev_idx;
                for (int j=size-1; j>i; --j)
                {
                    if (cur<nums[j] && nums[j]<min_greater)
                    {
                        min_greater = nums[j];
                        min_greater_idx = j;
                    }
                }
                nums[i] = min_greater;
                nums[min_greater_idx] = cur;
                std::sort(nums.begin()+i+1, nums.end());
                swapped = true;
                break;
            }
            if (cur > max_prev)
            {
                max_prev = cur;
                max_prev_idx = i;
            }
        }
        
        if (!swapped)
        {
            for (int i=0; i<size/2; ++i)
            {
                int tmp = nums[i];
                nums[i] = nums[size-i-1];
                nums[size-i-1] = tmp;   
            }
        }
        
        return;
    }
};
