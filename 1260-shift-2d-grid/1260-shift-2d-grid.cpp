class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int rows = grid.size();
        int cols = grid[0].size();

        int total = rows * cols;

        k %= total;

        vector<vector<int>> ans(rows, vector<int>(cols));

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {

                int idx = i * cols + j;

                int newIdx = (idx + k) % total;

                int newRow = newIdx / cols;

                int newCol = newIdx % cols;

                ans[newRow][newCol] = grid[i][j];
            }
        }

        return ans;
    }
};