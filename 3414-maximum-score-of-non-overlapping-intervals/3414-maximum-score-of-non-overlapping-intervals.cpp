class Solution {
public:

    struct Node {
        long long score;
        vector<int> idx;

        Node() {
            score = 0;
        }

        Node(long long s, vector<int> v) {
            score = s;
            idx = v;
        }
    };

    
    bool better(const Node& a, const Node& b) {

        if (a.score != b.score)
            return a.score > b.score;

        return a.idx < b.idx;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();
        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }
        sort(a.begin(), a.end(),
            [](auto &x, auto &y) {
                if (x[1] != y[1])
                    return x[1] < y[1];

                return x[0] < y[0];
            }
        );
        vector<long long> ends(n);

        for (int i = 0; i < n; i++)
            ends[i] = a[i][1];

        
        vector<int> prev(n);

        for (int i = 0; i < n; i++) {

            long long start = a[i][0];

            int pos = lower_bound(
                ends.begin(),
                ends.begin() + i,
                start
            ) - ends.begin();

            prev[i] = pos - 1;
        }

        vector<vector<Node>> dp(
            n + 1,
            vector<Node>(5)
        );

       
        for (int i = 0; i <= n; i++)
            dp[i][0] = Node(0, {});

        for (int i = 1; i <= n; i++) {

            int id = i - 1;

           
            for (int k = 1; k <= 4; k++) {
                dp[i][k] = dp[i - 1][k];
            }

            
            for (int k = 1; k <= 4; k++) {

                int p = prev[id] + 1;

                Node candidate = dp[p][k - 1];

                candidate.score += a[id][2];

                
                auto it = lower_bound(
                    candidate.idx.begin(),
                    candidate.idx.end(),
                    (int)a[id][3]
                );

                candidate.idx.insert(
                    it,
                    (int)a[id][3]
                );

                if (better(candidate, dp[i][k])) {
                    dp[i][k] = candidate;
                }
            }
        }

       
        Node ans = dp[n][0];

        for (int k = 1; k <= 4; k++) {
            if (better(dp[n][k], ans))
                ans = dp[n][k];
        }

        return ans.idx;
    }
};