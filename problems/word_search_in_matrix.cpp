class Solution {
public:
    bool findSubstr(vector<vector<char>>& board,
                    string s,
                    int sidx,
                    int row,
                    int col,
                    std::set<std::pair<int, int>> &sused) {
        if (sidx == s.length()-1) return true;
        
        bool found;
        sused.insert(make_pair(row, col));
        // up
        if (row > 0 && sused.find(make_pair(row-1, col))==sused.end() && board[row-1][col]==s[sidx+1]) {
            found = findSubstr(board, s, sidx+1, row-1, col, sused);
            if (found) return true;
        }
        // down
        if (row < (board.size()-1) && sused.find(make_pair(row+1, col))==sused.end() && board[row+1][col]==s[sidx+1]) {
            found = findSubstr(board, s, sidx+1, row+1, col, sused);
            if (found) return true;
        }
        // left
        if (col > 0 && sused.find(make_pair(row, col-1))==sused.end() && board[row][col-1]==s[sidx+1]) {
            found = findSubstr(board, s, sidx+1, row, col-1, sused);
            if (found) return true;
        }
        // right
        if (col < (board[0].size()-1) && sused.find(make_pair(row, col+1))==sused.end() && board[row][col+1]==s[sidx+1]) {
            found = findSubstr(board, s, sidx+1, row, col+1, sused);
            if (found) return true;
        }
        
        sused.erase(make_pair(row, col));
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (!board.size() || !board[0].size() || !word.size())
            return false;
        
        std::set<std::pair<int, int>> sused;
        for (int row=0; row<board.size(); ++row) {
            for (int col=0; col<board[0].size(); ++col) {
                if (board[row][col] == word[0]) {
                    bool found = findSubstr(board, word, 0, row, col, sused);
                    if (found) return true;
                }
            }
        }
        
        return false;
    }
};
