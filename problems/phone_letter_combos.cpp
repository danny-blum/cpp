class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<int, string> m = { {2,"abc"}, {3,"def"}, {4,"ghi"}, {5,"jkl"}, {6,"mno"}, {7,"pqrs"}, {8,"tuv"}, {9,"wxyz"} };
        vector<string> combos;
        vector<string> combos_prev;
        
        for (int i=0; i<digits.length(); i++)
        {
            string s = m[digits[i]-'0'];
            combos_prev = combos;
            combos.erase(combos.begin(), combos.end());
            for (int j=0; j<s.length(); j++)
            {
                if (combos_prev.empty())
                    combos.push_back(string(1,s[j]));
                else
                {
                    for (int k=0; k<combos_prev.size(); k++)
                    {
                        combos.push_back(combos_prev[k] + s[j]);
                    }
                }
            }
        }
        
        return combos;
    }
};
