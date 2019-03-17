class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int startRow;
        int endRow;
        int startCol;
        int endCol;
        int cur = 1;
        int i;
        int j;
        vector<vector<int>> m(n, std::vector<int>(n));
        
        for (startRow=0; startRow<(n+1)/2; ++startRow)
        {
            startCol = startRow;
            endRow = n - startRow;
            endCol = n - startCol;
            for (j=startCol; j<endCol; ++j)
                m[startRow][j] = cur++;
            for (i=startRow+1; i<endRow; ++i)
                m[i][endCol-1] = cur++;
            for (j=endCol-2; j>=startCol; --j)
                m[endRow-1][j] = cur++;
            for (i=endRow-2; i>=startRow+1; --i)
                m[i][startCol] = cur++;            
        }
        
        return m;
    }
};
