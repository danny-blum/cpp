class Solution {
public:
    int myAtoi(string str) {
        bool skip_ws = true;
        bool negative = false;
        bool looking_for_sign = true;
        long long ret = 0;
        
        for (int i=0; i<str.length(); i++)
        {
            if (skip_ws)
            {
                if (str[i]==' ')
                    continue;
                else
                    skip_ws = false;
            }

            if (ret==0 && looking_for_sign && str[i]=='-')
            {
                negative = true;
                looking_for_sign = false;
            }
            else if (ret==0 && looking_for_sign && str[i]=='+')
            {
                looking_for_sign = false;
                continue;
            }
            else if (isdigit(str[i]))
            {
                ret *= 10;
                ret += (int)(str[i] - '0');
                looking_for_sign = false;
            }
            else
            {
                break;
            }
            
            if (negative)
            {
                if (-ret <= INT_MIN)
                {
                    ret = INT_MIN;
                    break;
                }
            }
            else
            {
                if (ret >= INT_MAX)
                {
                    ret = INT_MAX;
                    break;
                }
            }   
        }
        
        if (negative)
            ret = -ret;
        
        return (int)ret; 
    }
};
