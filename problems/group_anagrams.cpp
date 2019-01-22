class Solution {
public:
    
    bool mapEqual(map<char, int> &m1, map<char, int> &m2) {
        if (m1.size() != m2.size()) return false;
        
        return std::equal(m1.begin(), m1.end(), m2.begin());
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> vvout;
        vector<map<char, int>> vmana;
        
        for(int i=0; i<strs.size(); ++i)
        {
            string s = strs[i];
            map<char, int> m;
            for (int j=0; j<s.length(); ++j)
            {
                if (m.find(s[j]) == m.end())
                    m[s[j]] = 1;
                else
                    m[s[j]]++;
            }
            bool found = false;
            for (int ana=0; ana<vvout.size(); ++ana)
            {
                if (mapEqual(m, vmana[ana]))
                {
                    found = true;
                    vvout[ana].push_back(s);
                    break;
                }
            }
            if (!found)
            {
                vvout.push_back(vector<string>(1,s));
                vmana.push_back(m);
            }                  
        }

        return vvout;
    }
};
