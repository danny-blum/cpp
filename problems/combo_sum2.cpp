class Solution {
public:
    
    void combos(vector<int>& candidates, int target, int start, vector<int> vcur, vector<vector<int>> &vret) {
        target -= candidates[start];
        vcur.push_back(candidates[start]);
        
        if (target == 0)
        {
            vret.push_back(vcur);
            return;
        }
        
        int prev = 0;
        for (int i=start+1; i<candidates.size() && candidates[i]<=target; ++i)
        {
            if (candidates[i] != prev)
                combos(candidates, target, i, vcur, vret);
            prev = candidates[i];
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> vret;
        std::sort(candidates.begin(), candidates.end());
        
        int prev = 0;
        for (int i=0; i<candidates.size() && candidates[i]<=target; ++i)
        {
            vector<int> v;
            if (candidates[i] != prev)
                combos(candidates, target, i, v, vret);
            prev = candidates[i];
        }
        
        return vret;
    }
};
