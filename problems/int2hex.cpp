class Solution {
public:
    string toHex(int num) {
        char out[9];
        bool start = false;
        int pos = 0;
        
        for (int i=7; i>=0; --i)
        {
            unsigned int shift = i*4;
            unsigned int mask = 0xf << shift;
            unsigned int val = (num & mask) >> shift;
            char c;
            if (val < 10)
                c = val + '0';
            else
                c = (val-10) + 'a';
            if (c!='0' || start)
            {
                start = true;
                out[pos] = c;
                pos++;
            }
        }
        
        if (pos == 0)
        {
            out[0] = '0';
            pos++;
        }
        out[pos] = '\0';

        string ret(out);
        return ret;
    }
};
