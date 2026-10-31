class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int MOD = 1e9 + 7;

        vector<vector<int>> R(m, vector<int>(n, 0));
        vector<vector<int>> D(m, vector<int>(n, 0));

        R[0][0] = 1;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 0) {

                    int ways = (R[i][j] + D[i][j]) % MOD;

                    if(j + 1 < n)
                        R[i][j+1] = (R[i][j+1] + ways) % MOD;

                    if(i + 1 < m)
                        D[i+1][j] = (D[i+1][j] + ways) % MOD;
                }
                else {
                    if(i + 1 < m)
                        D[i+1][j] = (D[i+1][j] + R[i][j]) % MOD;

                    if(j + 1 < n)
                        R[i][j+1] = (R[i][j+1] + D[i][j]) % MOD;
                }
            }
        }
        return (R[m-1][n-1] + D[m-1][n-1]) % MOD;
    }
};