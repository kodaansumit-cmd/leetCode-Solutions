class Solution {
public:

    bool isCycleDFS(int src, vector<vector<int>> &adj,
                    vector<bool> &vis, vector<bool> &recPath) {

        vis[src] = true;
        recPath[src] = true;

               for (int v : adj[src]) {

            
            if (!vis[v]) {
                if (isCycleDFS(v, adj, vis, recPath))
                    return true;
            }

            
            else if (recPath[v]) {
                return true;
            }
        }

        
        recPath[src] = false;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        
        vector<vector<int>> adj(numCourses);

        
        for (auto &edge : prerequisites) {
            int course = edge[0];
            int prereq = edge[1];

            adj[prereq].push_back(course);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> recPath(numCourses, false);

        
        for (int i = 0; i < numCourses; i++) {

            if (!vis[i]) {

                if (isCycleDFS(i, adj, vis, recPath))
                    return false;      
            }
        }

        return true;  
    }
};