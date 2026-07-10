class Solution {
public:

    vector<int> pathExistenceQueries(
        int n,
        vector<int>& nums,
        int maxDiff,
        vector<vector<int>>& queries
    ) {

        const int LOG = 20;

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        vector<vector<int>> jump(n, vector<int>(LOG));

        int right = n - 1;

        
        for (int left = n - 1; left >= 0; left--) {

            while (arr[right].first - arr[left].first > maxDiff) {
                right--;
            }

            int node = arr[left].second;

            jump[node][0] = arr[right].second;

            for (int j = 1; j < LOG; j++) {
                jump[node][j] =
                    jump[jump[node][j - 1]][j - 1];
            }
        }

        vector<int> answer;

        for (auto& q : queries) {

            int u = q[0];
            int v = q[1];

           
            if (nums[u] > nums[v]) {
                swap(u, v);
            }

            if (u == v) {
                answer.push_back(0);
                continue;
            }

            if (nums[u] == nums[v]) {
                answer.push_back(1);
                continue;
            }

            int steps = 0;

            for (int j = LOG - 1; j >= 0; j--) {

                int nxt = jump[u][j];

                if (nums[nxt] < nums[v]) {

                    steps += (1 << j);

                    u = nxt;
                }
            }

            if (nums[jump[u][0]] < nums[v]) {
                answer.push_back(-1);
            }
            else {
                answer.push_back(steps + 1);
            }
        }

        return answer;
    }
};