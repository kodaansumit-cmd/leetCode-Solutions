class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<array<long long, 3>> sortedTasks;

        for (int i = 0; i < n; i++) {
            sortedTasks.push_back({
                tasks[i][0], tasks[i][1], i
            });
        }
        sort(sortedTasks.begin(), sortedTasks.end());

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        vector<int> ans;
        long long time = 0;
        int i = 0;

        while (i < n || !pq.empty()) {
            if (pq.empty() && time < sortedTasks[i][0]) {
                time = sortedTasks[i][0];
            }
            while (i < n && sortedTasks[i][0] <= time) {
                pq.push({
                    sortedTasks[i][1],
                    (int)sortedTasks[i][2]
                });
                i++;
            }
            auto [processingTime, index] = pq.top();
            pq.pop();

            ans.push_back(index);
            time += processingTime;
        }
        return ans;
    }
};