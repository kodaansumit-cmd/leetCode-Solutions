class Solution {
public:

    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        
        vector<bool> inMST(n, false);

        
        vector<int> minCost(n, INT_MAX);

       
        minCost[0] = 0;

        int answer = 0;

        
        for (int i = 0; i < n; i++) {

            int node = -1;

            
            for (int j = 0; j < n; j++) {

                if (!inMST[j] &&
                    (node == -1 || minCost[j] < minCost[node])) {

                    node = j;
                }
            }

            
            inMST[node] = true;

           
            answer += minCost[node];

           
            for (int j = 0; j < n; j++) {

                if (!inMST[j]) {

                    int distance =
                        abs(points[node][0] - points[j][0]) +
                        abs(points[node][1] - points[j][1]);

                    minCost[j] = min(minCost[j], distance);
                }
            }
        }

        return answer;
    }
};