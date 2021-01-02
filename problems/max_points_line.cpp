class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int size = points.size();
        if (size == 0)
            return 0;
        unordered_map<string, int> lm;
        int same;
        int ret = 1;
        
        for (int i=0; i<size; ++i)
        {
            lm.clear();
            same = 1;
            for (int j=i+1; j<size; ++j)
            {
                int y = points[j][1] - points[i][1];
                int x = points[j][0] - points[i][0];
                if (y==0 && x==0)
                {
                    same++;
                    continue;
                }
                
                int g = gcd(x, y);
                x /= g;
                y /= g;
                
                string key = to_string(x) + "_" + to_string(y);
                lm[key]++;
            }
            
            ret = max(ret, same);
            for(auto it=lm.begin(); it!=lm.end(); ++it)
            {
                ret = max(ret, it->second + same);
            }
        }
        
        return ret;
    }
private:
    int gcd(int a, int b) {
        while (b != 0)
        {
            a = a % b;
            swap(a, b);
        }
        
        return a;
    }
};
