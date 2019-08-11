class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        bool prevDup = false;
        int iOut = -1;
        int iIn = 0;
        bool inc;
        
        for (iIn=0; iIn < nums.size(); ++iIn) {
            if (iIn == 0)
                inc = true;
            else {
                if (nums[iIn] == nums[iIn-1])
                {
                    if (prevDup)
                        inc = false;
                    else {
                        prevDup = true;
                        inc = true;
                    }
                }
                else {
                    inc = true;
                    prevDup = false;
                }
            }
            if (inc) {
                iOut++;
                nums[iOut] = nums[iIn];
            }
        }
        
        return iOut + 1;
    }
};
