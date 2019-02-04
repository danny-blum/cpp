class Solution {
public:
    
    int fdiagIdx(int row, int col, int n) {
        if (col >= row)
            return col - row;
        else
            return (row-col) + n-1;
    }
    
    int rdiagIdx(int row, int col) {
        return row + col;
    }

    void checkRow(vector<string> &board,
                   vector<bool> &cols,
                   vector<bool> &fdiags,
                   vector<bool> &rdiags,
                   int n,
                   int row,
                   vector<vector<string>> &sols) {   
        for (int j=0; j<n; ++j)
        {
            if (!cols[j] && !fdiags[fdiagIdx(row,j,n)] && !rdiags[rdiagIdx(row,j)])
            {
                board[row][j] = 'Q';
                if (row == (n-1))
                {
                    sols.push_back(board);
                }
                else
                {
                    cols[j] = true;
                    fdiags[fdiagIdx(row,j,n)] = true;
                    rdiags[rdiagIdx(row,j)] = true;
                    checkRow(board, cols, fdiags, rdiags, n, row+1, sols);
                    cols[j] = false;
                    fdiags[fdiagIdx(row,j,n)] = false;
                    rdiags[rdiagIdx(row,j)] = false;     
                }
                board[row][j] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false);
        vector<bool> fdiags(2*n - 1, false);
        vector<bool> rdiags(2*n -1, false);
        vector<vector<string>> sols;
        
        if (n <= 0)
            return sols;
        
        checkRow(board, cols, fdiags, rdiags, n, 0, sols);
        
        return sols;
    }
};
