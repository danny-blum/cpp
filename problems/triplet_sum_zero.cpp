class Solution {
public:
    int increment(vector<int> &v, int idx) {
        do
        {
            idx++;
        }
        while (idx<(v.size()-1) && v[idx]==v[idx-1]);
        
        return idx;
    }
    
    int decrement(vector<int> &v, int idx) {
        do
        {
            idx--;
        }
        while (idx>0 && v[idx]==v[idx+1]);
        
        return idx;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> v = nums;
        vector<vector<int>> vret;
        
        std::sort(v.begin(), v.end());
        int idxs;
        int idxe;
        int sum;
        
        for (int idxn=0; idxn<v.size(); idxn=increment(v, idxn))
        {
            idxs = idxn + 1;
            idxe = v.size() - 1;
            
            while (idxs < idxe)
            {
                sum = v[idxn] + v[idxs] + v[idxe];
                if (sum == 0)
                {
                    vector<int> vent;
                    vent.push_back(v[idxn]);
                    vent.push_back(v[idxs]);
                    vent.push_back(v[idxe]);
                    vret.push_back(vent);
                    idxs = increment(v, idxs);
                    idxe = decrement(v, idxe);
                }
                else if (sum < 0)
                    idxs = increment(v, idxs);
                else
                    idxe = decrement(v, idxe);
            }
        }
        
        return vret;
    }
};
