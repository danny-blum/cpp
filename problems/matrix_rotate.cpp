class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int ip;
        int jp;
        int n = matrix.size();
        int tmp;
        
        for (int i=0; i<=(n-1)/2; i++)
        {
            for (int j=0; j<n/2; j++)
            {
                ip = n-i-1;
                jp = n-j-1;
                tmp = matrix[i][j];
                matrix[i][j] = matrix[jp][i];
                matrix[jp][i] = matrix[ip][jp];
                matrix[ip][jp] = matrix[j][ip];
                matrix[j][ip] = tmp;
            }
        }
    }
};
