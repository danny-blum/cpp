class Solution {
public:
    vector<int> grayCode(int n) {
        if (n<0) return(vector<int>());
        vector<int> v(1<<n);

/*
        if (n == 0) {
            v.push_back(0);
            return v;
        }
        
        v = grayCode(n-1);
        int base = 1 << (n-1);
        for (int i=v.size()-1; i>=0; --i)
            v.push_back(v[i] + base);
*/
        
        v[0] = 0;
        if (n > 0) v[1] = 1;
        int base = 1;
        int idx;
        for (int nn=2; nn<=n; ++nn) {        
            base <<= 1;
            idx = base;
            for (int i=base-1; i>=0; --i)
                v[idx++] = (v[i] + base);
        }
        
        return v;
    }    
};
