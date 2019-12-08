class Solution {
public:
    int numDecodings(string s) {
        vector<int> mem(s.length(), -1);
        return numDecodingsMem(0, s, mem);
    }
    
private:
    int numDecodingsMem(int start, string s, vector<int> &mem) {
        if (start >= s.length()) return 0;
        if (mem[start] != -1) return mem[start];
        int sint = (int)(s[start] - '0');
        if (sint <= 0) return 0;
        if (start == (s.length()-1)) return 1;
        
        if ((sint > 2) ||
            (sint == 2 && (s[start+1]-'0') > 6)) {
            mem[start] = numDecodingsMem(start+1, s, mem);
            return mem[start];
        }
        
        if (start == (s.length()-2)) {
            if ((s[start+1]-'0') == 0)
                mem[start] = 1;
            else
                mem[start] = 2;
        }
        else
            mem[start] = numDecodingsMem(start+1, s, mem) +
                         numDecodingsMem(start+2, s, mem);
        
        return mem[start];
    }
};
