class Solution {
public:
    bool binarySearch(vector<int>& nums, int target, int low, int high) {
        if (nums[low]==target || nums[high]==target)
            return true;
        if (low == high)
            return false;
        int mid = ((high - low) / 2) + low;
        if (nums[mid] == target)
            return true;
        
        if (target > nums[mid]) {
            if (target < nums[high])
                return binarySearch(nums, target, mid+1, high);
            if (nums[high] <= nums[mid] && mid<high)
                if (binarySearch(nums, target, mid+1, high))
                    return true;
            if (nums[low] >= nums[mid] && low<mid)
                return binarySearch(nums, target, low, mid-1);
        }
        else {
            if (target > nums[low])
                return binarySearch(nums, target, low, mid-1);
            if (nums[low] >= nums[mid] && low<mid)
                if (binarySearch(nums, target, low, mid-1))
                    return true;
            if (nums[high] <= nums[mid] && mid<high)
                return binarySearch(nums, target, mid+1, high);
        }
        
        return false;
    }
    
    bool search(vector<int>& nums, int target) {
        if (!nums.size())
            return false;
        return binarySearch(nums, target, 0, nums.size()-1);
    }
};
