class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() ==0 ) {
            return false;
        }
        int low =0;
        int high, mid;
        int m = matrix.size();
        int n = matrix[0].size();
        high = (m*n)-1;
        while (low <= high) {
            mid = low + (high-low)/2;
            int r = mid/n;
            int c = mid%n;
            
            if (matrix[r][c] == target) {
                return true;
            }
            else if (matrix[r][c]< target) {
                low = mid + 1;
            }
            else {
                high = mid-1;
            }
        }
        return false;
    }
};