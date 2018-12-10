class Solution {
public:
    string countAndSay(int n) {
        if (n<=1) return "1";
        
        string tmp = countAndSay(n-1);
        string ret;
        int num = 0;
        int count = 0;
        for (int i=0; i<tmp.size(); i++)
        {
            if (!num)
            {
                num = tmp[i] - '0';
                count = 1;
            }
            else if (tmp[i]==(num+'0'))
            {
                count++;  
            }
            else
            {
                ret += (count + '0');
                ret += (num + '0');
                num = tmp[i] - '0';
                count = 1;
            }
        }
        ret += (count + '0');
        ret += (num + '0');
        
        return ret;
    }
};
