class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        int left = 0, right = cols - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int maxRow = 0;

            for (int i = 1; i < rows; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }
            int leftVal = (mid > 0) ? mat[maxRow][mid - 1] : -1;
            int rightVal = (mid < cols - 1) ? mat[maxRow][mid + 1] : -1;

            if (mat[maxRow][mid] > leftVal &&
                mat[maxRow][mid] > rightVal) {
                return {maxRow, mid};
            }
            else if (leftVal > mat[maxRow][mid]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return {-1, -1};
    }
};