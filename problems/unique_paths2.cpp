class Solution {
public:
    int findPaths(int c, int r, vector<vector<int>>& grid, vector<vector<int>>& paths) {
        if (grid[c][r] == 1)
            return 0;
        
        int right, down;
        
        if (paths[c+1][r] >=0)
            right = paths[c+1][r];
        else
            right = findPaths(c+1, r, grid, paths);
        
        if (paths[c][r+1] >=0)
            down = paths[c][r+1];
        else
            down = findPaths(c, r+1, grid, paths);        
        
        paths[c][r] = right + down;
        
        return right + down;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int cols = obstacleGrid.size();
        if (!cols) return 0;
        int rows = obstacleGrid[0].size();
        if (!rows) return 0;
        if (obstacleGrid[cols-1][rows-1] == 1)
            return 0;

        vector<vector<int>> paths(cols, vector<int>(rows, -1));
        paths[cols-1][rows-1] = 1;
        
        bool blocked = false;
        for (int c=cols-2; c>=0; --c)
        {
            if (obstacleGrid[c][rows-1] == 1)
                blocked = true;
            paths[c][rows-1] = (blocked) ? 0 : 1;            
        }
        blocked = false;
        for (int r=rows-2; r>=0; --r)
        {
            if (obstacleGrid[cols-1][r] == 1)
                blocked = true;
            paths[cols-1][r] = (blocked) ? 0 : 1;            
        }
        
        if (rows==1 || cols==1)
            return paths[0][0];
        
        return findPaths(0, 0, obstacleGrid, paths);
    }
};
