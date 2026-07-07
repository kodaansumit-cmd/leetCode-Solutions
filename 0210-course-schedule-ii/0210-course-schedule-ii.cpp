class Solution {
public:
    bool dfs(int src, vector<vector<int>>& adj,
             vector<bool>& vis,
             vector<bool>& recPath,
             vector<int>& ans) {

        vis[src] = true;
        recPath[src] = true;

        for (int v : adj[src]) {

            if (!vis[v]) {
                if (dfs(v, adj, vis, recPath, ans))
                    return true;
            }
            else if (recPath[v]) {
                return true;
            }
        }

        recPath[src] = false;

        ans.push_back(src);     
        return false;
    }

    vector<int> findOrder(int numCourses,
                          vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for (auto &e : prerequisites)
            adj[e[1]].push_back(e[0]);

        vector<bool> vis(numCourses, false);
        vector<bool> recPath(numCourses, false);

        vector<int> ans;

        for (int i = 0; i < numCourses; i++) {

            if (!vis[i]) {
                if (dfs(i, adj, vis, recPath, ans))
                    return {};
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};