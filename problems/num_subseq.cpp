class Solution {
public:
    int numDistinct(string s, string t) {
        int slen = s.length();
        int tlen = t.length();
        if (slen < tlen) return 0;
        if (tlen == 0)
            return 1; 
        
        std::vector<std::vector<int>> mem(slen+1, std::vector<int>(tlen+1, -1));
        
        return numDistinctSub(s, t, 0, 0, mem);
    }
private:
    int numDistinctSub(string s, string t, int soff, int toff, std::vector<std::vector<int>> &mem) {
        int slen = s.length() - soff;
        int tlen = t.length() - toff;
        if (slen < tlen) return 0;
        if (tlen == 0)
            return 1;
        
        int subseqs = 0;
        for (int i=0; i<=slen-tlen; ++i) {
            if (s[soff+i] == t[toff])
                if (mem[soff+i+1][toff+1] != -1)
                    subseqs += mem[soff+i+1][toff+1];
                else
                    subseqs += numDistinctSub(s, t, soff+i+1, toff+1, mem);
        }
        
        mem[soff][toff] = subseqs;
        return subseqs;
    }
};
