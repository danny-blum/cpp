class Solution {
public:
    const int num_rows = 9;
    const int num_cols = 9;
    
    struct CellState {
    public:
        int r;
        int c;
        int dof;
        
        CellState(int row, int col, int dof) : r(row), c(col), dof(dof) {}
    };
    
#if 0
    struct HighestDof
    {
        bool operator()(const CellState& lhs, const CellState& rhs) const
        {
            return lhs.dof > rhs.dof;
        }
    };
#endif
    
    struct BoardState {
    public:
        vector<vector<char>> cur_board;
//        std::priority_queue<CellState, std::vector<CellState>, HighestDof> pqempty;
//        std::queue<CellState> pqempty;
        std::list<CellState> pqempty;

        vector<bitset<9>> set_cols;
        vector<bitset<9>> set_rows;
        vector<bitset<9>> set_3x3s;
        int num_empty;
        
        BoardState(vector<vector<char>>& board) : 
            cur_board(board), set_cols(9, 0), set_rows(9, 0), set_3x3s(9, 0), num_empty(0) {}
    };
    
    int get3x3(int row, int col) {
        return (row/3)*3 + col/3;
    }
    pair<int, int> get_rc_3x3(int n3x3, int k) {
        int row = (n3x3/3)*3 + k/3;
        int col = (n3x3%3)*3 + k%3;
        
        return make_pair(row, col);
    }
    
    bool solve(BoardState &bs) {
        if (bs.num_empty == 0) return true;
        bool found = false;
        CellState cs = bs.pqempty.front();
        bs.pqempty.pop_front();
        int row = cs.r;
        int col = cs.c;
        bitset<9> set_all = bs.set_cols[col] | bs.set_rows[row] | bs.set_3x3s[get3x3(row,col)];
        int val = 0;
        while (val<9 && !found)
        {
            if (set_all[val]==0)
            {
                BoardState bs_test = bs;
                bs_test.cur_board[row][col] = val + '1';
                bs_test.num_empty--;
                bs_test.set_cols[col][val] = 1;
                bs_test.set_rows[row][val] = 1;
                bs_test.set_3x3s[get3x3(row,col)][val] = 1;
//cout << "set_all:" << set_all << " setting row:" << row << " col:" << col << " to val:" << val+1 << "qempty size:" << bs_test.qempty.size() << endl;
                found = solve(bs_test);
                if (found)
                {
                    bs = bs_test;
                    break;
                }
            }
            val++;
        }

//if (bs.qempty.size() < 20)
//    cout << "set_all:" << set_all << " row:" << row << " col:" << col << " qempty size:" << bs.qempty.size() << " num_empty:" << bs.num_empty << endl;
        return found;   
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        BoardState bs(board);
        int num_empty = 0;
        
        for (int row=0; row<num_rows; ++row)
        {
            for (int col=0; col<num_cols; ++col)
            {           
                char c = bs.cur_board[row][col];
                if (c != '.')
                {
                    int val = static_cast<int>(c - '0') - 1;
                    bs.set_cols[col][val] = 1;
                    bs.set_rows[row][val] = 1;
                    bs.set_3x3s[get3x3(row,col)][val] = 1;
                }
                else
                {
                    bs.num_empty++;
                }
            }
        }
        
        for (int row=0; row<num_rows; ++row)
        {
            for (int col=0; col<num_cols; ++col)
            {
                int dof_cur = 0;
                if (bs.cur_board[row][col] == '.')
                {
                    bitset<9> set_all = (bs.set_cols[col] | bs.set_rows[row] | bs.set_3x3s[get3x3(row,col)]);
                    for (int n=0; n<9; ++n)
                    {
                        if (!set_all[n])
                            dof_cur++;
                    }
                    CellState cs(row, col, dof_cur);
                    if (dof_cur == 1)
                        bs.pqempty.push_front(cs);
                    else
                        bs.pqempty.push_back(cs);
                }
            }
        }
        
        bool ret = solve(bs);

        if (ret)
        {
            //cout << "solved!!!" << endl;
            board = bs.cur_board;
        }
        else
        {
            //cout << "not solved!!!" << endl;
        }
    }
};
