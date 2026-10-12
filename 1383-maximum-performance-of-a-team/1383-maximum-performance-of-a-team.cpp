class Solution {
public:
    int maxPerformance(int n, vector<int>& speed,
                       vector<int>& efficiency, int k) {
        const int MOD = 1e9 + 7;
        vector<pair<int, int>> engineers;

        for (int i = 0; i < n; i++) {
            engineers.push_back({efficiency[i], speed[i]});
        }
        sort(engineers.rbegin(), engineers.rend());
        priority_queue<int, vector<int>, greater<int>> pq;

        long long sumSpeed = 0;
        long long ans = 0;

        for (auto [eff, spd] : engineers) {
            pq.push(spd);
            sumSpeed += spd;

            if (pq.size() > k) {
                sumSpeed -= pq.top();
                pq.pop();
            }
            long long performance = sumSpeed * eff;
            ans = max(ans, performance);
        }
        return ans % MOD;
    }
};