class Solution {
public:
    
    bool byte_valid(const string &s)
    {
        int byte_int = std::stoi(s);
        if (byte_int <= 255)
            return true;
        
        return false;
    }
    
    vector<string> placeDot(int dotsRem, string &s, vector<string> v) {
        int len = s.length();
        vector<string> vout;
        
        for (int sn=0; sn<v.size(); sn++)
        {
            int usedLen = v[sn].length() - (3-dotsRem);
            int startPos = usedLen;
            int minSize = 2 - ((dotsRem+1)*3 - len + startPos);
            if (minSize < 0) minSize = 0;
            
            for (int i=startPos+minSize; i<(len-1)&&i<startPos+3; i++) 
            {
                string byte = string(s, startPos, i-startPos+1);
                if (byte_valid(byte))
                {
                    string tmp(v[sn] + byte + ".");
                    vout.push_back(tmp);
                }
            }
        }
        
        return vout;
    }
    
    void add_last_byte(vector<string> &v, string &s) {
        vector<string>::iterator it = v.begin();
        
        while (it != v.end())
        {
            int len = (*it).length() - 3;
            int rem = s.length() - len;
            string byte = string(s, s.length()-rem, rem);
            
            if (byte_valid(byte))
            {
                *it = *it + byte;
                ++it;
            }
            else
            {
                it = v.erase(it);
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        int len = s.length();
        int startPos;
        vector<string> v;
        
        if (s.length() < 4)
            return v;
        
        v.push_back("");
        for (int i=0; i<3; i++)
        {
            v = placeDot(3-i, s, v);
        }
        
        add_last_byte(v, s);
        
        return v;
    }
};
