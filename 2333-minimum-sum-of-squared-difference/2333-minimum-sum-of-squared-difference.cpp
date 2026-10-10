class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> diff(nums1.size());
        long long total = 0;

        for (int i = 0; i < nums1.size(); i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
        }

        long long k = (long long)k1 + k2;

        if (total <= k) return 0;

        int left = 0, right = 100000;

        while (left < right) {
            int mid = left + (right - left) / 2;
            long long needed = 0;

            for (int d : diff) {
                if (d > mid) needed += d - mid;
            }
            if (needed <= k)
                right = mid;
            else
                left = mid + 1;
        }

        long long ans = 0;
        long long used = 0;

        for (int d : diff) {
            if (d > left) {
                used += d - left;
                ans += 1LL * left * left;
            } else {
                ans += 1LL * d * d;
            }
        }
        long long remaining = k - used;
        ans -= remaining * (2LL * left - 1);
        return ans;
    }
};