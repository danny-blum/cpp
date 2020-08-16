class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> parts;
        
        if (s.length() > 0)
            subPartition(s, 0, parts);
        else
            parts.push_back(vector<string>());
        
        return parts;
    }
private:
    bool isPalindrome(string &s, int start, int end) {
        int sublen = (end-start) + 1;
        
        for (int i=0; i<sublen/2; ++i)
        {
            if (s[start+i] != s[end-i])
                return false;
        }
        
        return true;
    }
    
    void subPartition(string &s, int start, vector<vector<string>> &parts) {
        int len = s.length();
        
        for (int end=start; end<len; ++end)
        {
            if (start==end || isPalindrome(s, start, end))
            {
                string sp = s.substr(start, end-start+1);
                if (end == len-1)
                {
                    vector<string> vs;
                    vs.push_back(sp);
                    parts.push_back(vs);
                }
                else
                {
                    int partsPrevSize = parts.size();
                    subPartition(s, end+1, parts);
                    
                    for(int i=partsPrevSize; i<parts.size(); ++i)
                    {
                        parts[i].insert(parts[i].begin(), sp);
                    }
                }
            }
        }
    }  
};
