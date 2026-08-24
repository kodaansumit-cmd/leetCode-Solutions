class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int top = 0;
        int bottom = rows - 1;

        while (top <= bottom) {

            int midRow = top + (bottom - top) / 2;

            if (target >= matrix[midRow][0] &&
                target <= matrix[midRow][cols - 1]) {

                int left = 0;
                int right = cols - 1;

                while (left <= right) {

                    int mid = left + (right - left) / 2;

                    if (matrix[midRow][mid] == target) {
                        return true;
                    }
                    else if (matrix[midRow][mid] < target) {
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }

                return false;
            }
            else if (target > matrix[midRow][cols - 1]) {
                top = midRow + 1;
            }
            else {
                bottom = midRow - 1;
            }
        }

        return false;
    }
};