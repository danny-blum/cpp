class Solution {
public:
    bool isScramble(string s1, string s2) {
        int chars[26] = {0};
        int len = s1.length();
        if (len <=0) return false;
        
        for (int i=0; i<len; ++i) {
            chars[s1[i]-'a']++;
        }
        for (int i=0; i<len; ++i) {
            if (chars[s2[i]-'a'] == 0)
                return false;
            chars[s2[i]-'a']--;
        }
        if (len <= 3)
            return true;
        
        for (int i=1; i<len; ++i) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i))
                && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if (isScramble(s1.substr(0, i), s2.substr(len-i))
                && isScramble(s1.substr(i), s2.substr(0, len-i)))
                return true;            
        }
        
        return false;
    }
};
