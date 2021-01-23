class Solution {
public:
    string reverseWords(string s) {
        int len = s.length();
        string sout;
        int i1 = len-1;

        // skip trailing whitespace
        while (i1>0 && s[i1]==' ')
           i1--;
        int i2 = i1;
        
        bool firstWord = false;
        
        for (; i1>=0; --i1)
        {
            if (s[i1] == ' ')
            {                    
                if (firstWord)
                    sout += " ";
                
                sout += s.substr(i1+1, i2-i1);
                
                firstWord = true;
                
                // skip extra whitespace
                while (i1>0 && s[i1-1]==' ')
                    i1--;
                
                i1--;
                i2 = i1;
            }
        }
        
        if (i2 >= 0)
        {
            if (firstWord)
                sout += " ";
                
            sout += s.substr(0, i2+1);
        }
        
        return sout;
    }
};
