class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> best(n, INT_MAX);

        int left = 0;
        int sum = 0;
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            while (sum > target) {
                sum -= arr[left++];
            }

            if (sum == target) {
                int len = i - left + 1;

                if (left > 0 && best[left - 1] != INT_MAX) {
                    ans = min(ans, len + best[left - 1]);
                }

                best[i] = len;
            }

            if (i > 0) {
                best[i] = min(best[i], best[i - 1]);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};