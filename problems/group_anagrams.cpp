class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> vvout;
        unordered_map<string, vector<string>> mana;
        
        for(int i=0; i<strs.size(); ++i)
        {
            string s = strs[i];
            string ssort = s;
            std::sort(ssort.begin(), ssort.end());
            mana[ssort].push_back(s);
        }
         
        unordered_map<string, vector<string>>::iterator mana_iter;
        for (mana_iter=mana.begin(); mana_iter!=mana.end(); ++mana_iter)
        {
            vector<string> v(mana_iter->second.begin(), mana_iter->second.end());
            vvout.push_back(v);   
        }

        return vvout;
    }
};
