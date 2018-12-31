class Solution {
public:
    int rain_water(vector<int> &height, vector<int> &level, int i, int max_prev) {
        if (i >= height.size()) return 0;
        if (i == height.size()-1)
        {
            level[i] = height[i];
            return height[i];
        }
        
        int max_cur = max(height[i], max_prev);
        int max_next = rain_water(height, level, i+1, max_cur);
        
        level[i] = max(height[i], min(max_cur, max_next));
        
        return max(height[i], max_next);
    }
    
    int trap(vector<int>& height) {
        if (height.size() < 1) return 0;
        
        vector<int> level(height.size(), 0);
        level[0] = height[0];
        
        rain_water(height, level, 1, height[0]);
        
        int total_water = 0;
        for (int i=0; i<level.size(); ++i)
        {
            total_water += (level[i] - height[i]);
        }
        
        return total_water;
    }
};
