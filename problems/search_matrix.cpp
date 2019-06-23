class Solution {
public:
    bool bSearchRow(vector<int> &v, int target) {
        int size = v.size();
        int low = 0;
        int high = size - 1;
        int mid = high / 2;
        
        while (low <= high) {
            if (v[mid] == target)
                return true;
            if (v[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
            mid = ((high - low) / 2) + low;
        }
        
        return false;
    }
    
    int bSearchCol0(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int low = 0;
        int high = m - 1;
        int mid = high / 2;
        
        if (matrix[low][0] >= target)
            return low;
        if (matrix[high][0] <= target)
            return high;
        
        while (low <= high) {
            if (matrix[mid][0] <= target && matrix[mid+1][0] > target)
                break;
            if (matrix[mid][0] < target)
                low = mid + 1;
            else
                high = mid - 1;
            mid = ((high - low) / 2) + low;
        }
        
        return mid;
    }
    
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (!matrix.size() || !matrix[0].size())
            return false;
        int row = bSearchCol0(matrix, target);
        return bSearchRow(matrix[row], target);
    }
};
