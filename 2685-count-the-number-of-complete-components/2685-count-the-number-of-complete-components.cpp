class Solution {
public:
    vector<vector<int>> graph;
    vector<int> seen;

    void explore(int node, int &vertexCount, int &edgeCount) {
        seen[node] = 1;
        vertexCount++;
        edgeCount += graph[node].size();

        for (int next : graph[node]) {
            if (!seen[next]) {
                explore(next, vertexCount, edgeCount);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        graph.assign(n, {});
        seen.assign(n, 0);

        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        int complete = 0;

        for (int i = 0; i < n; i++) {
            if (seen[i]) continue;

            int vertices = 0;
            int degreeSum = 0;

            explore(i, vertices, degreeSum);

            int actualEdges = degreeSum / 2;
            int requiredEdges = vertices * (vertices - 1) / 2;

            if (actualEdges == requiredEdges)
                complete++;
        }

        return complete;
    }
};