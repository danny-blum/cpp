class Solution {
public:
    
    vector<vector<int>> comboSum(vector<int>& v, int target, int start, int end) {
        vector<vector<int>> vret;
        if (start > end) return vret;
        int repeat = 0;
        int num = 0;
        
        while (num <= target)
        {
            if (num == target)
            {
                vector<int> vt;
                for (int j=0; j<repeat; j++)
                    vt.push_back(v[start]);
                vret.push_back(vt);
            }
            else
            {
                if (num <= (target-v[start]))
                {
                    vector<vector<int>> vtmp = comboSum(v, target-num, start+1, end);
                    for (int i=0; i<vtmp.size(); ++i)
                    {
                        vector<int> vt;
                        for (int j=0; j<repeat; j++)
                            vt.push_back(v[start]);
                        vt.insert(vt.end(), vtmp[i].begin(), vtmp[i].end());
                        vret.push_back(vt);
                    }
                }
            }
            repeat++;
            num += v[start];
        }
        
        return vret;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int end = candidates.size() - 1;
        std::sort(candidates.begin(), candidates.end());
        
        while (end>=0 && candidates[end]>target)
            end--;
        
        return comboSum(candidates, target, 0, end);
    }
};
