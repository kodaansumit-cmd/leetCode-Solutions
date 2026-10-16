class Solution {
    static const int MOD = 1'000'000'007;

    struct SegmentTree {
        int n;
        vector<long long> sum, lazy;

        SegmentTree(int n) : n(n), sum(4 * n, 0),
                             lazy(4 * n, 0) {}

        void push(int node, int l, int r) {
            if (lazy[node] == 0 || l == r) return;

            int mid = (l + r) / 2;
            long long v = lazy[node];

            sum[node * 2] += v * (mid - l + 1);
            sum[node * 2 + 1] += v * (r - mid);

            lazy[node * 2] += v;
            lazy[node * 2 + 1] += v;

            lazy[node] = 0;
        }

        long long update(int node, int l, int r,
                         int ql, int qr) {
            if (qr < l || r < ql) return 0;

            if (ql <= l && r <= qr) {
                long long oldSum = sum[node];
                long long len = r - l + 1;

                sum[node] += len;
                lazy[node]++;

                return oldSum;
            }

            push(node, l, r);

            int mid = (l + r) / 2;

            long long oldSum =
                update(node * 2, l, mid, ql, qr) +
                update(node * 2 + 1, mid + 1, r, ql, qr);

            sum[node] = sum[node * 2] + sum[node * 2 + 1];

            return oldSum;
        }

        long long updateRange(int l, int r) {
            return update(1, 0, n - 1, l, r);
        }
    };

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        SegmentTree st(n);
        unordered_map<int, int> last;

        long long cur = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = last.count(nums[i])
                           ? last[nums[i]]
                           : -1;

            long long oldSum = st.updateRange(prev + 1, i);
            long long len = i - prev;

            cur = (cur + 2LL * oldSum + len) % MOD;
            ans = (ans + cur) % MOD;

            last[nums[i]] = i;
        }

        return (int)ans;
    }
};