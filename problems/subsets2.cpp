class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> vvout;
        if (!nums.size()) return vvout;
        
        std::sort(nums.begin(), nums.end());
        vvout.push_back(vector<int>());
        vvout.push_back(vector<int>(1,nums[0]));
        int prev = nums[0];
        int lastAdded = 1;
        
        for (int i=1; i<nums.size(); ++i) {
            int vvosize = vvout.size();
            if (nums[i] != prev) {
                lastAdded = 0;
                for (int j=0; j<vvosize; ++j) {
                    vector<int> v = vvout[j];
                    v.push_back(nums[i]);
                    vvout.push_back(v);
                    lastAdded++;
                }
            }
            else {
                int lastAddedCur = lastAdded;
                lastAdded = 0;
                for (int j=vvosize-lastAddedCur; j<vvosize; ++j) {
                    vector<int> v = vvout[j];
                    v.push_back(nums[i]);
                    vvout.push_back(v);
                    lastAdded++;
                }
            }
            prev = nums[i];
        }
        
        return vvout;
    }
};
