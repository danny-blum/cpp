class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        if (0 == rows) return 0;
        if (1 == rows) return triangle[0][0];
        
        vector<int> rowSums(rows, 0);
        
        rowSums[0] = triangle[0][0];
        for (int row=1; row<rows; ++row) {
            for (int col=row; col>=0; --col) {
                if (col == row)
                    rowSums[col] = triangle[row][col] + rowSums[col-1];
                else if (col == 0)
                    rowSums[col] = triangle[row][col] + rowSums[col];
                else
                    rowSums[col] = triangle[row][col] + std::min(rowSums[col-1], rowSums[col]);
            }
        }
        
        return *min_element(rowSums.begin(), rowSums.end());
    }
};
