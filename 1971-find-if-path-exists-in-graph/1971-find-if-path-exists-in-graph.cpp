class Solution {
public:

    bool dfs(int node, int destination,
             vector<vector<int>>& adj,
             vector<int>& visited)
    {
        if(node == destination)
            return true;

        visited[node] = 1;

        for(auto neighbour : adj[node])
        {
            if(!visited[neighbour])
            {
                if(dfs(neighbour, destination, adj, visited))
                    return true;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges,
                   int source, int destination)
    {
        vector<vector<int>> adj(n);

        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n,0);

        return dfs(source, destination, adj, visited);
    }
};