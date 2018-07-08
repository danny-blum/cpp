class Solution {
public:
    int maxArea(vector<int>& height) {
        map<int, vector<int>> m;
        
        for (int idx=0; idx<height.size(); idx++)
        {
            m[height[idx]].push_back(idx);
        }
        
        map<int, vector<int>>::reverse_iterator mit;
        int max_area = 0;
        int area;
        int i_min = INT_MAX;
        int i_max = INT_MIN;
        
        for (mit=m.rbegin(); mit!=m.rend(); ++mit)
        {
            if (mit->second[0] < i_min)
                i_min = mit->second[0];
            int vsize = mit->second.size();
            if (mit->second[vsize-1] > i_max)
                i_max = mit->second[vsize - 1];
            area = mit->first * (i_max - i_min);
            if (area > max_area)
                max_area = area;
        }
        
        return max_area;
    }
};
