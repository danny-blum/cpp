class Solution {
public:
    vector<vector<int>> combineSub(int n, int k, int start) {
        vector<vector<int>> vret;
        
        if (k == 1) {
            for (int i=start; i<=n; ++i) {
                vector<int> v;
                v.push_back(i);
                vret.push_back(v);
            }
            return vret;
        }
        
        vector<vector<int>> vsub = combineSub(n, k-1, start+1);
        for (int i=start; i<= (n-k + 1); ++i) {
            
            for (int j=0; j<vsub.size(); ++j) {
                if (vsub[j][0] > i) {
                    vector<int> v;
                    v.push_back(i);
                    v.insert(v.end(), vsub[j].begin(), vsub[j].end());
                    vret.push_back(v);
                }
            }
        }
        
        return vret;
    }
    
    vector<vector<int>> combine(int n, int k) {
        if (n<=0 || k<=0) {
            vector<vector<int>> vret;
            vector<int> v;
            vret.push_back(v);
            return vret;
        }

        return combineSub(n, k, 1);
    }
};
