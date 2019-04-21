class Solution {
public:
    
    int findSums(int c, int r, vector<vector<int>>& grid, vector<vector<int>>& sums) {
        int down, right;
        
        if (sums[c+1][r] >= 0)
            right = sums[c+1][r];
        else 
            right = findSums(c+1, r, grid, sums);
        
        if (sums[c][r+1] >= 0)
            down = sums[c][r+1];
        else 
            down = findSums(c, r+1, grid, sums);
        
        sums[c][r] = grid[c][r] + min(right, down);
        
        return sums[c][r];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        if (!grid.size() || !grid[0].size())
            return 0;
        int cols = grid.size();
        int rows = grid[0].size();
        vector<vector<int>> sums(cols, vector<int>(rows, -1));
        
        sums[cols-1][rows-1] = grid[cols-1][rows-1];
        for (int c=cols-2; c>=0; --c)
            sums[c][rows-1] = grid[c][rows-1] + sums[c+1][rows-1];
        for (int r=rows-2; r>=0; --r)
            sums[cols-1][r] = grid[cols-1][r] + sums[cols-1][r+1];    
        
        if (rows>1 && cols>1)
            return findSums(0, 0, grid, sums);
        else
            return sums[0][0];
    }
};
