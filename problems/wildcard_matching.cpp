class Solution {
public:
    bool isMatch(string s, string p) {
        int pi = 0;
        int si = 0;
        int btpi;
        int btsi;
        bool wild = false;
        
        if (p=="" && s!="")
            return false;
        
        while (pi < p.length())
        {
            if (si == s.length())
            {
                while (p[pi]=='*') pi++;
                if (pi == p.length()) return true;
                
                return false;
            }
            else if (p[pi]=='?' || p[pi]==s[si])
            {
                pi++;
                si++;
            }
            else if (p[pi] == '*')
            {
                while (p[pi+1]=='*')
                    pi++;
                if (pi == (p.length()-1))
                    return true;
                while (p[pi+1]!=s[si] && p[pi+1]!='?')
                {
                    if (si == s.length()-1)
                        return false;
                    si++;
                }

                // record backtrack position
                if (si < s.length()-1)
                {
                    wild = true;
                    btpi = pi;
                    btsi = si+1;
                }
                pi++;
            }
            else
            {
                // backtrack
                if (!wild) return false;
                pi = btpi;
                si = btsi;
            }
            
            if (pi==p.length() && si<s.length())
            {
                // backtrack
                if (!wild) return false;
                pi = btpi;
                si = btsi;
            }
        }
        
        return true;
    }
};
