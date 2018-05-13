class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        int start = 0;
        std::unordered_set<char> cset;
        
        if (s == "")
            return max_len;
                
        max_len++;
        int cur_len = max_len;
        cset.insert(s[0]);
        for (int i=1; i<s.length(); i++)
        {
            if (cset.find(s[i]) == cset.end())
            {
                cur_len++;
                cset.insert(s[i]);
            }
            else
            {
                if (cur_len > max_len)
                    max_len = cur_len;
                
                while(s[start] != s[i])
                {
                    cset.erase(s[start]);
                    start++;
                    cur_len--;
                }
                start++;
            }
        }
        if (cur_len > max_len)
            max_len = cur_len;
        
        return max_len;
    }
};
