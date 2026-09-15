class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int ans = 0, lastEnd = -1;

        for (int end = 0; end < n; end++) {
            for (int start = end; start >= 0; start--) {
                if (s[start] == s[end] &&
                    (end - start <= 1 || dp[start + 1][end - 1])) {
                    dp[start][end] = true;

                    if (end - start + 1 >= k && start > lastEnd) {
                        ans++;
                        lastEnd = end;
                    }
                }
            }
        }

        return ans;
    }
};