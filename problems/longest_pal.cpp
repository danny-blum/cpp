class Solution {
public:
    
    bool check_pal(string s, int start, int end)
    {
        bool is_pal = true;
        
        while (start < end)
        {
            if (s[start] != s[end])
            {
                is_pal = false;
                break;
            }
            
            start++;
            end--;
        }
        
        return is_pal;
    }
    
    string longestPalindrome(string s) {
        int max_len = 0;
        int max_start = 0;
        
        // Put character indicies in a map
        map<char,vector<int>> midx;
        for (int i=0; i<s.length(); ++i)
        {
            midx[s[i]].push_back(i);
        }
        
        for (int i=0; i<s.length(); ++i)
        {
            if (max_len >= (s.length()-i))
                break;
            
            for (int j=midx[s[i]].size()-1; j>=0; --j)
            {
                int end_idx = midx[s[i]][j];
                if (max_len > (end_idx-i))
                    break;
                if (end_idx>=i && check_pal(s, i, end_idx))
                {
                    int len = end_idx - i + 1;
                    if (len > max_len)
                    {
                        max_len = len;
                        max_start = i;
                    }
                }
            }
        }
        
        string max_pal = s.substr(max_start, max_len);
        
        return max_pal;
    }
};
