class Solution {
public:
    vector<string> generateParenthesis(int n) {        
        vector<string> combos;
        
        if (n < 1)
        {
            combos.push_back("");
            return combos;
        }
        
        generateCombos(n, 0, 0, "", combos);
        
        return combos;
    }

private:
    void generateCombos(int n, int numOpen, int totalOpened, string cur, vector<string> &combos) {
        if (cur.length() == 2*n)
        {
            combos.push_back(cur);
            return;
        }
        
        if (totalOpened < n)
            generateCombos(n, numOpen+1, totalOpened+1, cur+"(", combos);
        
        if (numOpen > 0)
            generateCombos(n, numOpen-1, totalOpened, cur+")", combos);
    }
};
