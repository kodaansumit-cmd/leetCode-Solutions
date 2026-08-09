class Solution {
public:

    int dp[101][101];
    int suffix[101];

    int n;

    int solve(int i, int M, vector<int>& piles) {

        if (i >= n)
            return 0;

        if (i + 2 * M >= n)
            return suffix[i];
        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;
        for (int X = 1; X <= 2 * M; X++) {


            int nextM = max(M, X);
            int opponent = solve(i + X, nextM, piles);
            int totalRemaining = suffix[i];
            int currentPlayer = totalRemaining - opponent;
            ans = max(ans, currentPlayer);
        }

        return dp[i][M] = ans;
    }
    int stoneGameII(vector<int>& piles) {

        n = piles.size();
        memset(dp, -1, sizeof(dp));

        suffix[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = piles[i] + suffix[i + 1];
        }
        return solve(0, 1, piles);
    }
};