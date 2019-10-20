class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        map<int, pair<int,int>> m;
        map<int, pair<int,int>>::iterator mit;
        int prev_height = 0;
        
        pair<int,int> pzero =  make_pair(0, 0);
        for (int i=0; i<heights.size(); ++i) {
            if (m.find(heights[i]) == m.end())
                m.insert({heights[i], pzero});
        }
        
        for (int i=0; i<heights.size(); ++i) {
            int old_cur = 0;
            
            if (heights[i] >= prev_height)
                mit = m.find(heights[i]);
            else {
                mit = m.find(prev_height);
                for (mit; mit->first > heights[i]; --mit) {
                    old_cur += mit->second.first;
                    if (old_cur > mit->second.second)
                        mit->second.second = old_cur;
                    mit->second.first = 0;
                }
            }
            mit->second.first += (old_cur + 1);
            if (mit->second.first > mit->second.second)
                mit->second.second = mit->second.first;

            prev_height = heights[i];
        }
        
        // reconcile final cur and max values
        map<int, pair<int,int>>::reverse_iterator rmit = m.rbegin();
        int final_cur = 0;
        for (rmit; rmit != m.rend(); ++rmit) {
            final_cur += rmit->second.first;
            if (final_cur > rmit->second.second)
                rmit->second.second = final_cur;
        }
        
        int area;
        int largest = 0;
        for(mit=m.begin(); mit!=m.end(); ++mit) {
            area = mit->second.second * mit->first;
            if (area > largest) largest = area;
        }
        
        return largest;
    }
};
