class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = INT_MAX;
        int len = nums.size();
        if (len < 3) return closest;
        
        int first;
        int mid;
        int last;
        int cur;
        int diff_cur;
        int diff = INT_MAX;
        
        std::sort(nums.begin(), nums.end());

        
        for (first=0; first<len-2; first++)
        {
            mid = first + 1;
            last = len - 1;
            
            while (mid < last)
            {
                cur = nums[first] + nums[mid] + nums[last];
                
                if (cur == target)
                    return target;
                else if (cur > target)
                    last--;
                else
                    mid++;
                
                diff_cur = abs(cur - target);
                if (diff_cur < diff)
                {
                    closest = cur;
                    diff = diff_cur;
                }
            }
        }
      
        return closest;
    }
};
