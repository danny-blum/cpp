class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int zeroR;
        int zeroC;
        bool zeroFound = false;
        int rows = matrix.size();
        if (rows == 0) return;
        int cols = matrix[0].size();
        if (cols == 0) return;
        
        // iterate through matrix, identify first 0
        for (int r=0; r<rows; ++r) {
            for (int c=0; c<cols; ++c) {
                if (matrix[r][c] == 0) {
                    if (!zeroFound) {
                        zeroR = r;
                        zeroC = c;
                        zeroFound = true;
                    }
                    else {
                        matrix[zeroR][c] = 0;
                        matrix[r][zeroC] = 0;
                    }
                }
            }
        }
        
        if (!zeroFound) return;
        
        // iterate through zeroR 
        for (int c=0; c<cols; ++c) {
            if (c == zeroC) continue;
            if (matrix[zeroR][c] == 0) {
                // zero out col
                for (int r=0; r<rows; ++r)
                    matrix[r][c] = 0;
            }
            matrix[zeroR][c] = 0;
        }
        
        // iterate through zeroC
        for (int r=0; r<rows; ++r) {
            if (r == zeroR) continue;
            if (matrix[r][zeroC] == 0) {
                // zero out row
                for (int c=0; c<cols; ++c)
                    matrix[r][c] = 0;
            }
            matrix[r][zeroC] = 0;
        }
    }
};
