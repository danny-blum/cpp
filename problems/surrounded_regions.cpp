class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if (!rows) return;
        int cols = board[0].size();
        if (!cols) return;
        
        for (int c=0; c<cols; ++c)
        {
            if ('O' == board[0][c])
            {
                markAdjacent(board, rows, cols, 0, c);
            } 
        }
        for (int r=1; r<rows; ++r)
        {
            if ('O' == board[r][0])
            {
                board[r][0] = 'F';
                markAdjacent(board, rows, cols, r, 0);
            } 
        }
        for (int r=1; r<rows; ++r)
        {
            if ('O' == board[r][cols-1])
            {
                board[r][cols-1] = 'F';
                markAdjacent(board, rows, cols, r, cols-1);
            } 
        }
        for (int c=1; c<cols-1; ++c)
        {
            if ('O' == board[rows-1][c])
            {
                board[rows-1][c] = 'F';
                markAdjacent(board, rows, cols, rows-1, c);
            } 
        }
        
        // Capture all regions not adjacent to a border 'O'
        for (int c=0; c<cols; ++c)
        {
            for (int r=0; r<rows; ++r)
            {
                if (board[r][c] == 'O')
                    board[r][c] = 'X';
                if (board[r][c] == 'F')
                    board[r][c] = 'O';
            }
        }
    }
private:    
    void markAdjacent(vector<vector<char>>& board, int rows, int cols, int r, int c)
    {
        board[r][c] = 'F';
        if (r > 0 && board[r-1][c] == 'O')
            markAdjacent(board, rows, cols, r-1, c);
        if (c > 0 && board[r][c-1] == 'O')
            markAdjacent(board, rows, cols, r, c-1);
        if ((r < rows-1) && board[r+1][c] == 'O')
            markAdjacent(board, rows, cols, r+1, c);
        if ((c < cols-1) && board[r][c+1] == 'O')
            markAdjacent(board, rows, cols, r, c+1);
    }
};
