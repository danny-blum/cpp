class Solution {
public:
    int minCut(string s) {
        int len = s.length();
        if (len == 0)
            return 0;
        
        vector<vector<bool>> isPal(len, vector<bool>(len, false));
        vector<int> vcuts(len, 0);
        
        for (int i=0; i<len; ++i)
        {
            int min = i;
            for (int j=0; j<=i; ++j)
            {
                if (s[j]==s[i] && ((i-1<j+1) || isPal[j+1][i-1]))
                {
                    isPal[j][i] = true;
                    min = (j==0) ? 0 : std::min(min, vcuts[j-1]+1);
                }
            }
            vcuts[i] = min;
        }
        
        return vcuts[len-1];
    }  
};
