class Solution {
public:
    int numTrees(int n) {
        vector<int> vTrees(n+1, -1);

        return numSubTrees(n, vTrees);
    }
private:
    int numSubTrees(int n, vector<int> &vTrees) {
        if (n <= 1)
            return 1;
        if (vTrees[n] != -1) return vTrees[n];
        int numUnique = 0;
        
        for (int i=1; i<=n; ++i) {
            numUnique += numSubTrees(i-1, vTrees) * numSubTrees(n-i, vTrees);
        }
        
        vTrees[n] = numUnique;
        return numUnique;
    }
};
