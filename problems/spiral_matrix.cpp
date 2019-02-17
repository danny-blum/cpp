class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> vret;
        if (matrix.size()==0 || matrix[0].size()==0) return vret;
        const int rows = matrix.size();
        const int cols = matrix[0].size();
        int rmin = 0;
        int rmax = rows-1;
        int cmin = 0;
        int cmax = cols-1;
        
        for (int level=0; level<(min(rows,cols)+1)/2; ++level)
        {
            for (int c=cmin; c<=cmax; ++c)
                vret.push_back(matrix[rmin][c]);
            for (int r=rmin+1; r<=rmax; ++r)
                vret.push_back(matrix[r][cmax]);
            if (cmax>cmin && rmax>rmin)
            {
                for (int c=cmax-1; c>=cmin; --c)
                    vret.push_back(matrix[rmax][c]);
                for (int r=rmax-1; r>=rmin+1; --r)
                    vret.push_back(matrix[r][cmin]);
            }
            
            rmin++;
            cmin++;
            rmax--;
            cmax--;
        }
        
        return vret;
    }
};
