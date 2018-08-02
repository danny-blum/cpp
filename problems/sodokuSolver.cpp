class Solution {
public:
    static const int numRows = 9;
    static const int numCols = 9;
    static const int numSubBoxes = 9;
    static const int numVals = 10;

    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        char c;
        int val;
        int subBox;
        vector<std::bitset<numVals>> rows(numRows, std::bitset<numVals>(0));
        vector<std::bitset<numVals>> cols(numCols, std::bitset<numVals>(0));
        vector<std::bitset<numVals>> subBoxes(numSubBoxes, std::bitset<numVals>(0));

        
        for (int row=0; row<numRows; row++)
        {
            for (int col=0; col<numCols; col++)
            {
                c = board[row][col];
                if (c != '.')
                {    
                    val = c - '0';
                    subBox = (row/3)*3 + col/3;
                    if (rows[row][val])
                        return false;
                    else
                        rows[row][val] = true;
                    if (cols[col][val])
                        return false;
                    else
                        cols[col][val] = true;
                    if (subBoxes[subBox][val])
                        return false;
                    else
                        subBoxes[subBox][val] = true;
                }
            }
        }
        
        return true;
    }
};
