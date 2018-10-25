class Solution {
public:
    
    int bsearch(vector<int>& nums, int target, int start, int end)
    {
        int size = end - start + 1;
        if (size <= 0) return -1;
        if (target == nums[start]) return start;
        if (size == 1) return -1;
        
        int mid = (end-start)/2 + start;
        if (target == nums[mid]) return mid;
        if (target == nums[end]) return end;
        if (nums[start] < nums[mid])
        {
            if (target<nums[mid] && target>nums[start])
                return bsearch(nums, target, start+1, mid-1);
            else
                return bsearch(nums, target, mid+1, end-1);
        }
        else
        {
            if (target<nums[start] && target>nums[mid])
                return bsearch(nums, target, mid+1, end-1);
            else
                return bsearch(nums, target, start+1, mid-1);                
        }
    }
    
    int search(vector<int>& nums, int target) {
        return bsearch(nums, target, 0, nums.size()-1);
    }
};
