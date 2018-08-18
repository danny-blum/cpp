class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        int first, second, third, fourth;
        int sum;
        
        if (nums.size() < 4)
            return ret;
        
        std::sort(nums.begin(), nums.end());
        
        for (first=0; first<nums.size()-3; increment(nums, first))
        {
            for (second=first+1; second<nums.size()-2; increment(nums, second))
            {
                third = second + 1;
                fourth = nums.size() - 1;
                
                while (third < fourth)
                {
                    sum = nums[first] + nums[second] + nums[third] + nums[fourth];
                    if (sum == target)
                    {
                        vector<int> v = {nums[first], nums[second], nums[third], nums[fourth]};
                        ret.push_back(v);
                        increment(nums, third);
                        decrement(nums, fourth);
                    }
                    else if (sum < target)
                    {
                        increment(nums, third);
                    }
                    else
                    {
                        decrement(nums, fourth);
                    }
                }   
            }   
        }
        
        return ret;
    }
private:
    int increment(vector<int>& v, int &i)
    {
        i++;
        while (i<v.size() && v[i]==v[i-1])
            i++;
        
        return i;
    }
    
    int decrement(vector<int>& v, int &i)
    {
        i--;
        while (i>0 && v[i]==v[i+1])
            i--;
        
        return i;
    }
};
