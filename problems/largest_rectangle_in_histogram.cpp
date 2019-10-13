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
/*
            if (m.find(heights[i]) == m.end()) {
                auto p = m.insert({heights[i], make_pair(0, 0)});
                mit = p.first;

                //  need to inherit from next highest......
                map<int, pair<int,int>>::iterator mit_next = std::next(mit);

                if (mit_next != m.end()) {
                    mit->second.first = mit_next->second.first;
                    mit->second.second = mit_next->second.second;
                }
            }
*/
            
            for(mit=m.begin(); mit!=m.end(); ++mit) {
                if (mit->first <= heights[i]) {
                    int cur = ++mit->second.first;
                    if (cur > mit->second.second) {
                        mit->second.second = cur;
                    }
                }
                else if (mit->first <= prev_height)
                    mit->second.first = 0;
                else
                    break;
            }
            prev_height = heights[i];
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
