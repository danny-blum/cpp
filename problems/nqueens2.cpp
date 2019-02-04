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

    int checkRow(vector<string> &board,
                   vector<bool> &cols,
                   vector<bool> &fdiags,
                   vector<bool> &rdiags,
                   int n,
                   int row) {
        int num_sols = 0;
        
        for (int j=0; j<n; ++j)
        {
            if (!cols[j] && !fdiags[fdiagIdx(row,j,n)] && !rdiags[rdiagIdx(row,j)])
            {
                board[row][j] = 'Q';
                if (row == (n-1))
                {
                    num_sols++;
                }
                else
                {
                    cols[j] = true;
                    fdiags[fdiagIdx(row,j,n)] = true;
                    rdiags[rdiagIdx(row,j)] = true;
                    num_sols += checkRow(board, cols, fdiags, rdiags, n, row+1);
                    cols[j] = false;
                    fdiags[fdiagIdx(row,j,n)] = false;
                    rdiags[rdiagIdx(row,j)] = false;     
                }
                board[row][j] = '.';
            }
        }
        
        return num_sols;
    }
        
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false);
        vector<bool> fdiags(2*n - 1, false);
        vector<bool> rdiags(2*n -1, false);
        int num_sols;
        
        if (n <= 0)
            return 0;
        
        num_sols = checkRow(board, cols, fdiags, rdiags, n, 0);
        
        return num_sols;
    }
};
