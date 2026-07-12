class Solution {
public:

    int findTheCity(int n, vector<vector<int>>& edges,
                    int distanceThreshold) {

        
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        
        for (auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            dist[u][v] = wt;
            dist[v][u] = wt;
        }

       
        for (int via = 0; via < n; via++) {

            for (int i = 0; i < n; i++) {

                for (int j = 0; j < n; j++) {

                    if (dist[i][via] == 1e9 ||
                        dist[via][j] == 1e9)
                        continue;

                    int newDistance =
                        dist[i][via] + dist[via][j];

                    dist[i][j] =
                        min(dist[i][j], newDistance);
                }
            }
        }

        int answerCity = -1;
        int minimumReachableCities = n;

        
        for (int city = 0; city < n; city++) {

            int reachable = 0;

            for (int nextCity = 0;
                 nextCity < n;
                 nextCity++) {

                if (city != nextCity &&
                    dist[city][nextCity] <= distanceThreshold) {

                    reachable++;
                }
            }

            
            if (reachable <= minimumReachableCities) {

                minimumReachableCities = reachable;
                answerCity = city;
            }
        }

        return answerCity;
    }
};