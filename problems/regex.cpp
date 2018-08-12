class Solution {
public:
    bool isMatch(string s, string p) {
        
        if (p=="")
            return (s=="");
        
        if (p.length()>1 && p[1]=='*')
            return isMatch(s.substr(0), p.substr(2)) || (s!="" && (s[0]==p[0] || p[0]=='.') && isMatch(s.substr(1), p.substr(0)));
        else
            return s!="" && (s!="" && (s[0]==p[0] || p[0]=='.')) && isMatch(s.substr(1), p.substr(1));
    }    
    
/*
    bool isMatch(string s, string p) {
        int s_idx = 0;
        int s_idx_loop_detect = -1;
        int p_idx = 0;
        int p_idx_restore;
        bool match_all = false;
        bool match_mult = false;
        char match_mult_ch;
        bool match_mult_prev = false;
        
        if (s=="" && p=="")
            return true;
        
        while (s_idx < s.length())
        {
cout << "s_idx:" << s_idx << " p_idx:" << p_idx << endl;
            if (p_idx>=p.length())
            {
                // check for match mult to end of s[]
                if (match_mult)
                {
                    bool check = true;
                    for (int i=s_idx; i<s.length(); i++)
                        if (s[i]!=match_mult_ch)
                            check = false;
                    if (check) return true;
                }
                
                if (!match_mult && !match_all)
                    return false;
                else if (match_all)
                {
                    p_idx = p_idx_restore;
                    if (s_idx_loop_detect == s_idx)
                        s_idx++;
                    s_idx_loop_detect = s_idx;
                }
            }
            
            if (match_mult)
            {
cout << "match_mult" << endl;
                if (s[s_idx]==match_mult_ch)
                {
                    s_idx++;
                    
                    if (p_idx<p.length() && (p[p_idx]==match_mult_ch || p[p_idx]=='.'))
                        p_idx++;
                }
                else
                {
                    match_mult = false;    // ?????????? What about followed by match_mult = 0???
                    match_mult_prev = true;
                }
            }
            else if (p[p_idx] == '.')
            {
                if (p_idx>=p.length()-1 || p[p_idx+1]!='*')
                    s_idx++;
                p_idx++;
                match_mult_prev = false;
            }
            else if (p[p_idx] == '*')
            {
                if (p_idx == 0)
                    return false;
                if (p[p_idx-1] == '.')
                {
                    match_all = true;
                    p_idx_restore = p_idx+1;
                }
                else
                {
                    match_mult = true;
                    match_mult_ch = p[p_idx-1];
                }
                p_idx++;
                match_mult_prev = false;
            }
            else
            {
                if (s[s_idx] == p[p_idx])
                {
                    if (p_idx>=p.length()-1 || p[p_idx+1]!='*')
                        s_idx++;
                    p_idx++;
                }
                else if (p_idx<p.length()-1 && p[p_idx+1]=='*')  // skip match prev
                {
                    p_idx += 2;
                    if (match_mult_prev)
                        match_mult = true;
                }
                else if (match_all)  // match all
                {
                    s_idx++;
                    p_idx = p_idx_restore;
                }
                else
                    return false;
                match_mult_prev = false;
            }
        }
cout << "END: s_idx:" << s_idx << " p_idx:" << p_idx << endl;
        
        while (p_idx<p.length()-1 && p[p_idx+1]=='*')
            p_idx+=2;
            
        while (p_idx<p.length() && p[p_idx]=='*')
            p_idx++;
        
        while (p_idx<p.length() && (match_mult|match_mult_prev) && (p[p_idx]==match_mult_ch || p[p_idx]=='.'))
            p_idx++;
        
        if (p_idx != p.length())
            return false;
        
        return true;
    }
*/
};
