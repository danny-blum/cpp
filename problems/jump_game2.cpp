class Solution {
public:
        
    int jump(vector<int>& nums) {
        int level = 0;
        int lmin = 0;
        int lmax = 0;
        
        while (lmax < nums.size()-1)
        {
            int tmax = lmax;
            for (int i=lmin; i<=lmax; ++i)
            {
                if (i+nums[i] > tmax)
                    tmax = i+ nums[i];
            }
            
            level++;
            lmin = lmax + 1;
            lmax = tmax;
        }
        
        return level;
    }
};
