class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        
        vector<pair<int, int>> adj[n + 1];

        for (auto &it : times) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }

        
        vector<int> dist(n + 1, INT_MAX);

        
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {

            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            
            for (auto &it : adj[node]) {

                int neighbour = it.first;
                int weight = it.second;

                if (d + weight < dist[neighbour]) {

                    dist[neighbour] = d + weight;

                    pq.push({dist[neighbour], neighbour});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {

            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};