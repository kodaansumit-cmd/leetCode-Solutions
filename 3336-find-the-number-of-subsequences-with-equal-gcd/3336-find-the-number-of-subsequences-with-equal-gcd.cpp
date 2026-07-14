class Solution {
public:
    static const int MOD = 1e9 + 7;

    int subsequencePairCount(vector<int>& nums) {

        int maxi = *max_element(nums.begin(), nums.end());

        vector<vector<long long>> dp(
            maxi + 1,
            vector<long long>(maxi + 1, 0)
        );

        dp[0][0] = 1;

        for (int x : nums) {

            vector<vector<long long>> next = dp;

            for (int g1 = 0; g1 <= maxi; g1++) {

                for (int g2 = 0; g2 <= maxi; g2++) {

                    if (dp[g1][g2] == 0)
                        continue;

                    long long ways = dp[g1][g2];

                    
                    int ng1 = (g1 == 0) ? x : gcd(g1, x);

                    next[ng1][g2] =
                        (next[ng1][g2] + ways) % MOD;

                   
                    int ng2 = (g2 == 0) ? x : gcd(g2, x);

                    next[g1][ng2] =
                        (next[g1][ng2] + ways) % MOD;
                }
            }

            dp = next;
        }

        long long ans = 0;

        for (int g = 1; g <= maxi; g++) {

            ans = (ans + dp[g][g]) % MOD;
        }

        return ans;
    }
};