class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> vret;
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        int start = -1;
        int end = -1;
        
        // Search for start of range
        while (low <= high)
        {
            mid = (high-low)/2 + low;
            if (nums[mid]==target && (mid==0 || nums[mid-1]!=target))
            {
                start = mid;
                break;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        if (start == -1)
        {
            vret.push_back(start);
            vret.push_back(end);
            return vret;
        }
        
        // Search for end of range
        low = mid;
        high = nums.size()-1;
        while (low <= high)
        {
            mid = (high-low)/2 + low;
            if (nums[mid]==target && (mid==(nums.size()-1) || nums[mid+1]!=target))
            {
                end = mid;
                break;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        vret.push_back(start);
        vret.push_back(end);
        return vret;
    }
};
