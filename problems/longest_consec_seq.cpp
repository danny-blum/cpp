class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_map<int, int> m;
        int maxSeq = 0;
        
        for (int i=0; i<nums.size(); ++i)
        {
            int seq = 0;
            int ahead = 0;
            int behind = 0;
            
            if (m.find(nums[i]) == m.end())    // Current num not already added
            {
                seq = 1;
                if (m.find(nums[i]+1) != m.end())  // num+1 already found
                {
                    ahead = m[nums[i]+1];
                    seq += ahead;
                }
                if (m.find(nums[i]-1) != m.end())  // num-1 already found
                {
                    behind = m[nums[i]-1];
                    seq += behind;
                    m[nums[i]-behind] = seq;
                }
                m[nums[i]] = seq;
                m[nums[i]+ahead] = seq;
            }
            
            if (seq > maxSeq)
                maxSeq = seq;
        }
        
        return maxSeq;
    }
};
