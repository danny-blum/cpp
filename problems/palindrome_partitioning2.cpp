class Solution {
public:
    int minCut(string s) {
        int len = s.length();
        if (len == 0)
            return 0;
        
        vector<vector<bool>> isPal(len, vector<bool>(len, false));
        
        return subPartition(s, 0, isPal);
    }
    
private:
    bool isPalindrome(string &s, int start, int end, vector<vector<bool>> &isPal) {
        int sublen = (end-start) + 1;
        
        if (s[start] != s[end])
            return false;
        
        if (sublen>2 || !isPal[start+1][end-1])
        {
            for (int i=1; i<sublen/2; ++i)
            {
                if (s[start+i] != s[end-i])
                    return false;
            }
        }
        
        isPal[start][end] = true;
        return true;
    }
    
    int subPartition(string &s, int start, vector<vector<bool>> &isPal) {
        int len = s.length();
        int minCuts = INT_MAX;
        
        for (int end=start; end<len; ++end)
        {
            if (start==end || isPalindrome(s, start, end, isPal))
            {
                if (end == len-1)
                {
                    return 0;
                }
                else
                {
                    int curCuts = subPartition(s, end+1, isPal) + 1;
                    if (curCuts < minCuts)
                        minCuts = curCuts;
                }
            }
        }
        
        return minCuts;
    }    
};
