class Solution {
public:
    int longestValidParentheses(string s) {
        int cur_level = 0;
        vector<int> vlevels(s.length());
        map<int, int> mclosed;
        
        for (int i=0; i<s.length(); i++)
        {
            if (s[i] == '(')
            {
                cur_level++;
            }
            else
            {
                cur_level--;
                mclosed[cur_level] = i;
            }
            
            vlevels[i] = cur_level;
        }
        
        bool in_run = false;
        int run_level;
        int run_length = 0;
        int max_run_length = 0;
        for (int i=0; i<s.length(); i++)
        {
            if (!in_run)
            {
                if (s[i]=='(' && mclosed.find(vlevels[i]-1)!=mclosed.end() && mclosed[vlevels[i]-1]>i)
                {
                    in_run = true;
                    run_level = vlevels[i];
                    run_length++;
                }
            }
            else
            {
                run_length++;
                if (s[i] == ')' && vlevels[i]==(run_level-1))
                {
                    if (run_length > max_run_length)
                        max_run_length = run_length;
                    if (i==s.length()-1 || mclosed.find(vlevels[i+1]-1)==mclosed.end() || mclosed[vlevels[i+1]-1]<=i)
                    {
                        // end run
                        run_length = 0;
                        in_run = false;
                    }
                }
                else if (s[i] == ')' && vlevels[i]==(run_level-2))
                {
                    // end run
                    run_length = 0;
                    in_run = false;
                }
            }
        }
        
        return max_run_length;
    }
};
