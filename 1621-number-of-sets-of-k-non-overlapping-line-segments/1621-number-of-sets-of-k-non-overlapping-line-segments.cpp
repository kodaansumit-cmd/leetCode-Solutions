class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1e9 + 7;

        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
        vector<vector<long long>> pref(n + 1, vector<long long>(k + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            pref[i][0] = pref[i - 1][0] + dp[i][0];
        }

        for (int j = 1; j <= k; j++) {
            for (int i = 1; i <= n; i++) {

                dp[i][j] = dp[i - 1][j];

                if (i >= 2) {
                    dp[i][j] += pref[i - 1][j - 1];
                    dp[i][j] %= MOD;
                }

                pref[i][j] = pref[i - 1][j] + dp[i][j];
                pref[i][j] %= MOD;
            }
        }

        return dp[n][k];
    }
};