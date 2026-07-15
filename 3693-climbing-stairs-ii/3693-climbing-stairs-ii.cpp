class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {

        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;

        for (int i = 0; i <= n; i++) {

            if (dp[i] == INT_MAX)
                continue;

            for (int jump = 1; jump <= 3; jump++) {

                int next = i + jump;

                if (next <= n) {

                    int currentCost;

                    if (next == 0) {
                        currentCost = 0;
                    } else {
                        currentCost = costs[next - 1] + jump * jump;
                    }

                    dp[next] = min(
                        dp[next],
                        dp[i] + currentCost
                    );
                }
            }
        }

        return dp[n];
    }
};