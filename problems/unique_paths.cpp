class Solution {
public:

    int calcPaths(int c, int r, int m, int n, vector<vector <int>> &paths) {
        
        if (c==1 || r==1)
            return 1;
        
        if (paths[c][r]>0)
            return paths[c][r];
        
        if (r<m && c<n && paths[r][c]>0)
        {
            paths[c][r] = paths[r][c];
            return paths[c][r];
        }
        
        int right;
        if (paths[c-1][r]>0)
            right = paths[c-1][r];
        else
            right = calcPaths(c-1, r, m, n, paths);
        
        if (c == r)
        {
            paths[c][r] = right * 2;
            return paths[c][r];
        }
        
        int down;
        if (paths[c][r-1]>0)
            down = paths[c][r-1];
        else
            down = calcPaths(c, r-1, m, n, paths);
        
        paths[c][r] = right + down;
        return paths[c][r];
    }
    
    int uniquePaths(int m, int n) {
        
        if (m==0 || n==0)
            return 0;
        
        vector<vector <int>> paths(m+1, vector<int>(n+1, -1));
        
        return calcPaths(m, n, m, n, paths);
    }
};
