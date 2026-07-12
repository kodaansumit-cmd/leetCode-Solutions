class Solution {
public:

    int timer = 0;

    void dfs(int node, int parent,
             vector<int>& disc,
             vector<int>& low,
             vector<vector<int>>& adj,
             vector<vector<int>>& ans)
    {
        disc[node] = low[node] = timer++;

        for (int neigh : adj[node]) {

           
            if (neigh == parent)
                continue;

            
            if (disc[neigh] == -1) {

                dfs(neigh, node, disc, low, adj, ans);

                low[node] = min(low[node], low[neigh]);

               
                if (low[neigh] > disc[node]) {
                    ans.push_back({node, neigh});
                }
            }

            
            else {

                low[node] = min(low[node], disc[neigh]);
            }
        }
    }

    vector<vector<int>> criticalConnections(
        int n,
        vector<vector<int>>& connections)
    {
        vector<vector<int>> adj(n);

        for (auto edge : connections) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> disc(n, -1);
        vector<int> low(n, -1);

        vector<vector<int>> ans;

        dfs(0, -1, disc, low, adj, ans);

        return ans;
    }
};