class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (0 == s.length())
            return false;
        if (0 == wordDict.size())
            return false;
        
        vector<bool> checked(s.length(), false);
        
        return wordBreakSub(s, wordDict, checked, 0);
    }
    
private:
    bool wordBreakSub(string s, vector<string>& wordDict, vector<bool> &checked, int idx) {
        if (idx == s.length())
            return true;
        
        if (checked[idx])
            return false;
        
        for (int i=0; i<wordDict.size(); ++i)
        {
            string sdict = wordDict[i];
            if (0 == s.compare(idx, sdict.length(), sdict))
            {
                if (wordBreakSub(s, wordDict, checked, idx+sdict.length()))
                    return true;
            }
        }
        
        checked[idx] = true;
        return false;
    }
};
